//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0646_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0646_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 经典贪心题，直接背诵：最多不相交区间
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int res = 1;
        auto ed = pairs[0][1];
        for (int i = 1; i < (int) pairs.size(); ++i) {
            if (pairs[i][0] <= ed) {
                continue;
            }
            ++res;
            ed = max(ed, pairs[i][1]);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0646_H
