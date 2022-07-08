//
// Created by Fengwei Zhang on 2/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0699_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0699_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 首先，我们要准确描述正方形的底边，这里我们用3个点描述底边：左端点、中点、右端点；我们将左、右端点放大1倍，保证中点为整数
    // 然后，我们将上述坐标保序离散化（排序、去重），并根据这些点初始化线段树（4*n个节点）；初始时，高度h=0
    // 遍历positions，记录当前底边对应的高度、更新新高度；若底边坐标为(a,b)，查询范围为(a+1,b-1)
    // 带懒标记的线段树，结点保存当前区间高度的最大值h
public:
    vector<int> fallingSquares(const vector<vector<int>> &positions) {
        vector<int> xs;  // 离散化的横坐标
        xs.reserve(positions.size() * 3);
        for (const auto &x: positions) {
            auto a = x[0];
            auto b = x[0] + x[1];
            xs.emplace_back(a * 2);  // 使中点坐标为整数(a+b)
            xs.emplace_back(b * 2);
            xs.emplace_back(a + b);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        Node tree[(xs.size() + 1) * 4];
        buildTree(1, 1, (int) xs.size(), tree);
        vector<int> ans;
        ans.reserve(positions.size());
        for (const auto &x: positions) {
            auto a = x[0];
            auto b = x[0] + x[1];
            a = getIdx(a * 2, xs);
            b = getIdx(b * 2, xs);
            auto h = query(1, a + 1, b - 1, tree);
            modify(1, a, b, h + x[1], tree);
            ans.emplace_back(tree[1].h);
        }
        return ans;
    }

private:
    struct Node {
        int l, r;  // 区间范围
        int h;  // 区间高度
        int inc;  // 懒标记，高度增量

        Node() {
            l = -1, r = -1;
            h = 0;
            inc = 0;
        }

        Node(int l, int r, int h, int inc) {
            this->l = l;
            this->r = r;
            this->h = h;
            this->inc = inc;
        }
    };

    void buildTree(int u, int l, int r, Node tree[]) {
        tree[u] = {l, r, 0, 0};
        if (l >= r) {
            return;
        }
        auto mid = l + (r - l) / 2;
        buildTree(u << 1, l, mid, tree);
        buildTree(u << 1 | 1, mid + 1, r, tree);
    }

    void modify(int u, int l, int r, int h, Node tree[]) {  // 更新某区间的高度
        if (tree[u].l >= l && tree[u].r <= r) {
            tree[u].h = h;
            tree[u].inc = h;
            return;
        }
        pushDown(u, tree);
        auto mid = tree[u].l + (tree[u].r - tree[u].l) / 2;
        if (l <= mid) {
            modify(u << 1, l, r, h, tree);
        }
        if (r > mid) {
            modify(u << 1 | 1, l, r, h, tree);
        }
        pushUp(u, tree);
    }

    int query(int u, int l, int r, Node tree[]) {
        if (tree[u].l >= l && tree[u].r <= r) {
            return tree[u].h;
        }
        pushDown(u, tree);
        auto mid = tree[u].l + (tree[u].r - tree[u].l) / 2;
        int res = 0;
        if (l <= mid) {
            res = max(res, query(u << 1, l, r, tree));
        }
        if (r > mid) {
            res = max(res, query(u << 1 | 1, l, r, tree));
        }
        return res;
    }

    void pushUp(int u, Node tree[]) {
        tree[u].h = max(tree[u << 1].h, tree[u << 1 | 1].h);
    }

    void pushDown(int u, Node tree[]) {
        if (tree[u].inc) {
            auto inc = tree[u].inc;
            auto &l = tree[u << 1];
            auto &r = tree[u << 1 | 1];
            l.h = inc;  // 这里的数据更新是直接复写
            r.h = inc;
            l.inc = inc;
            r.inc = inc;
            tree[u].inc = 0;
        }
    }

    int getIdx(int x, vector<int> &xs) {
        return (int) (lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0699_H
