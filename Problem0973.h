//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0973_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0973_H

#include <vector>

using namespace std;

class Solution {
    // 快速选择算法：参见 AcWing 786
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        quickSelect(points, 0, (int) points.size() - 1, k);
        return {points.begin(), points.begin() + k};
    }

private:
    void quickSelect(vector<vector<int>> &points, int st, int ed, int k) {
        if (st >= ed) {
            return;
        }
        auto p = distFromSrc(points[st + (ed - st) / 2]);
        auto l = st - 1;
        auto r = ed + 1;
        while (l < r) {
            while (distFromSrc(points[++l]) < p);
            while (distFromSrc(points[--r]) > p);
            if (l < r) {
                swap(points[l], points[r]);
            }
        }
        if (k <= r - st + 1) {
            quickSelect(points, st, r, k);
        } else {
            quickSelect(points, r + 1, ed, k - (r - st + 1));
        }
    }

    static int distFromSrc(vector<int> &a) {
        return a[0] * a[0] + a[1] * a[1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0973_H
