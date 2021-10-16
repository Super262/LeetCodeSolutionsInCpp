//
// Created by Fengwei Zhang on 10/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0850_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0850_H

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Problem0850 {
private:
    struct Segment {
        int x, y1, y2;
        int k;

        bool operator<(const Segment &t) const {
            return x < t.x;
        }
    };

    struct Node {
        int l, r;
        int cnt;
        int length;
    };

    int getIdx(const vector<int> &ys, double y) {
        return (int) (lower_bound(ys.begin(), ys.end(), y) - ys.begin());
    }

    void pushUp(Node nodes[], const vector<int> &ys, const int idx) {
        if (nodes[idx].cnt != 0) {
            nodes[idx].length = ys[nodes[idx].r + 1] - ys[nodes[idx].l];
            return;
        }
        if (nodes[idx].l != nodes[idx].r) {
            nodes[idx].length = nodes[idx << 1].length + nodes[idx << 1 | 1].length;
        } else {
            nodes[idx].length = 0;
        }
    }

    void buildTree(Node nodes[], const int idx, const int l, const int r) {
        nodes[idx] = {l, r, 0, 0};
        if (l == r) {
            return;
        }
        auto mid = l + ((r - l) >> 1);
        buildTree(nodes, idx << 1, l, mid);
        buildTree(nodes, idx << 1 | 1, mid + 1, r);
    }

    void modifyNode(Node nodes[], const vector<int> &ys, const int idx, const int l, const int r, const int val) {
        if (nodes[idx].l >= l && nodes[idx].r <= r) {
            nodes[idx].cnt += val;
            pushUp(nodes, ys, idx);
            return;
        }
        auto mid = nodes[idx].l + ((nodes[idx].r - nodes[idx].l) >> 1);
        if (l <= mid) {
            modifyNode(nodes, ys, idx << 1, l, r, val);
        }
        if (r > mid) {
            modifyNode(nodes, ys, idx << 1 | 1, l, r, val);
        }
        pushUp(nodes, ys, idx);
    }

public:
    int rectangleArea(const vector<vector<int>> &rectangles) {
        const int n = (int) rectangles.size();
        Segment segs[2 * n];
        Node nodes[4 * 2 * n + 10];
        vector<int> ys;
        for (int i = 0, j = 0; i < n; ++i) {
            const auto &rec = rectangles[i];
            segs[j++] = {rec[0], rec[1], rec[3], 1};
            segs[j++] = {rec[2], rec[1], rec[3], -1};
            ys.emplace_back(rec[1]);
            ys.emplace_back(rec[3]);
        }
        sort(segs, segs + 2 * n);
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        buildTree(nodes, 1, 0, (int) ys.size() - 2);
        int result = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (i > 0) {
                result += (int) ((long long) nodes[1].length * (segs[i].x - segs[i - 1].x) % 1000000007);
                result %= 1000000007;
            }
            modifyNode(nodes, ys, 1, getIdx(ys, segs[i].y1), getIdx(ys, segs[i].y2) - 1, segs[i].k);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0850_H
