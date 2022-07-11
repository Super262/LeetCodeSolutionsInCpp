//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0715_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0715_H

#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class RangeModule {
    // 动态线段数会超时，这里使用"有序集合+线性查找"替代
    // 初始化，插入2个"哨兵"节点（正无穷和负无穷），保证所有查找操作不会返回无效值
    // 查找区间(l,r)时，查询关键字为(l,INF)，先通过upper_bound找到位置i，再执行i--，这时i->first<=l，再判断i->second>=r是否成立
    // 添加区间(l,r)时，首先要找到所有可能和(l,r)相交的区间：查询关键字为(l,-INF)，使用lower_bound找到i，后移i，直到i->second>=left
    // 若i->first<=right，i是和(l,r)相交的最靠左的区间；设置j=i，后移j，找到和当前区间相交的最右区间；构建新区间t，删除[i:j]间所有区间，再插入t
    // 删除操作和插入操作类似，区别在于我们需要构建新的区间
public:
    RangeModule() {  // 初始化，加入2个哨兵
        rs.insert({-INF, -INF});
        rs.insert({INF, INF});
    }

    void addRange(int left, int right) {
        auto i = rs.lower_bound({left, -INF});  // 找到可能和当前区间相交的区间
        --i;
        while (i->second < left) {
            ++i;
        }
        if (i->first > right) {  // 无交集，直接插入
            rs.insert({left, right});
            return;
        }
        auto j = i;
        while (j->first <= right) {  // 找到和当前区间相交的最右区间
            ++j;
        }
        --j;
        pair<int, int> t(min(i->first, left), max(j->second, right));
        while (i != j) {  // 删掉[i:j]间所有区间
            auto k = i;
            ++k;
            rs.erase(i);
            i = k;
        }
        rs.erase(j);
        rs.insert(t);
    }

    bool queryRange(int left, int right) {  // 要找左端点小于等于left的区间
        auto i = rs.upper_bound({left, INF});
        i--;
        return i->second >= right;
    }

    void removeRange(int left, int right) {
        auto i = rs.lower_bound({left, -INF});  // 找到可能和当前区间相交的区间
        --i;
        while (i->second < left) {
            ++i;
        }
        if (i->first > right) {  // 无交集，不操作
            return;
        }
        auto j = i;
        while (j->first <= right) {  // 找到和当前区间相交的最右区间
            ++j;
        }
        --j;
        auto a = subtract(*i, {left, right});  // a = i - {l,r}
        auto b = subtract(*j, {left, right});  // b = j - {l,r}
        while (i != j) {  // 删掉[l:r]间所有区间
            auto k = i;
            ++k;
            rs.erase(i);
            i = k;
        }
        rs.erase(j);
        for (const auto &x: a) {
            rs.insert(x);
        }
        for (const auto &x: b) {
            rs.insert(x);
        }
    }

private:
    set<pair<int, int>> rs;
    static const int INF = 0x3f3f3f3f;

    static vector<pair<int, int>> subtract(pair<int, int> a, pair<int, int> b) {  // 区间a减去b后的剩余区间
        vector<pair<int, int>> res;
        if (a.first < b.first) {
            if (a.second > b.second) {
                res.emplace_back(a.first, b.first);
                res.emplace_back(b.second, a.second);
            } else {
                res.emplace_back(a.first, b.first);
            }
        } else {
            if (a.second > b.second) {
                res.emplace_back(b.second, a.second);
            }
        }
        return res;
    }
};

/*class RangeModule {
    // 动态线段树，我们不会预先分配4*N个节点，而是按需开辟；对于每个节点，ls、rs分别指向左孩子、右孩子，sum表示当前区间和（为0或length），
    // length是区间长度，add是懒标记；添加新区间时，我们设置懒标记为1，从根开始执行更新操作
    //
public:
    RangeModule() {
        root = new Node();
    }

    void addRange(int left, int right) {
        update(root, 1, N - 1, left, right - 1, 1);
    }

    bool queryRange(int left, int right) {
        return query(root, 1, N - 1, left, right - 1) == right - left;
    }

    void removeRange(int left, int right) {
        update(root, 1, N - 1, left, right - 1, -1);
    }

private:
    struct Node {
        int sum;
        int add;
        Node *ls;
        Node *rs;

        Node() {
            sum = 0;
            add = 0;
            ls = nullptr;
            rs = nullptr;
        }
    };

    const int N = 1e9 + 10;

    Node *root;

    void pushUp(Node *node) {
        node->sum = node->ls->sum + node->rs->sum;
    }

    void pushDown(Node *node, int len) {
        if (!node->ls) {
            node->ls = new Node();
        }
        if (!node->rs) {
            node->rs = new Node();
        }
        if (node->add == 0) {
            return;
        }
        if (node->add == 1) {
            node->ls->sum = len - len / 2;
            node->rs->sum = len / 2;
        } else {
            node->ls->sum = 0;
            node->rs->sum = 0;
        }
        node->ls->add = node->add;
        node->rs->add = node->add;
        node->add = 0;
    }

    int query(Node *node, int l, int r, int st, int ed) {
        if (st <= l && r <= ed) {
            return node->sum;
        }
        pushDown(node, r - l + 1);
        auto mid = l + (r - l) / 2;
        int ans = 0;
        if (st <= mid) {
            ans += query(node->ls, l, mid, st, ed);
        }
        if (ed > mid) {
            ans += query(node->rs, mid + 1, r, st, ed);
        }
        return ans;
    }

    void update(Node *node, int l, int r, int st, int ed, int add) {
        auto len = r - l + 1;
        if (st <= l && r <= ed) {
            node->add = add;
            if (add == 1) {
                node->sum = len;
            } else {
                node->sum = 0;
            }
            return;
        }
        pushDown(node, len);
        auto mid = l + (r - l) / 2;
        if (st <= mid) {
            update(node->ls, l, mid, st, ed, add);
        }
        if (ed > mid) {
            update(node->rs, mid + 1, r, st, ed, add);
        }
        pushUp(node);
    }
};*/

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0715_H
