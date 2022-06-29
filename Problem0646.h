//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0646_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0646_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 贪心，按照右端点对所有区间升序排序，再从头开始遍历，判断相交关系
    // 最多不相交区间，同AcWing 908
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int ans = 1;
        auto ed = pairs[0][1];
        for (int i = 1; i < (int) pairs.size(); ++i) {
            if (pairs[i][0] <= ed) {
                continue;
            }
            ++ans;
            ed = max(ed, pairs[i][1]);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0646_H
