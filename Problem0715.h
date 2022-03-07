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
    // 经典算法，直接背诵
    // 线段数或Splay是最好的做法，这里使用"有序集合+线性查找"替代
    // https://www.acwing.com/solution/content/39931/
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
        --i;
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

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0715_H
