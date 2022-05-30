//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0436_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0436_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 对于任意i，我们要找到j，使得intervals[j]和intervals[i]最接近
    // 题目对i、j的大小关系没有要求，因此我们直接排序intervals，再进行二分查找
    // i、j是原intervals内元素的索引，排序前应记录下每个元素的索引
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        const auto n = (int) intervals.size();
        for (int i = 0; i < n; ++i) {
            intervals[i].emplace_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> res(n, -1);
        for (const auto &x: intervals) {
            int l = 0;
            int r = n - 1;
            while (l < r) {
                auto mid = l + (r - l) / 2;
                if (intervals[mid][0] >= x[1]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (intervals[r][0] >= x[1]) {
                res[x[2]] = intervals[r][2];
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0436_H
