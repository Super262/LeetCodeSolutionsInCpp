//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1014_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1014_H

#include <vector>

using namespace std;

class Problem1014 {
    // 双指针问题：我们希望找到i、j，满足i<j，且(values[j]-j)+(values[i]+i)最大
public:
    int maxScoreSightseeingPair(const vector<int> &values) {
        int ans = INT_MIN;
        int max_prev = INT_MIN;
        for (int i = 0; i < (int) values.size(); ++i) {
            ans = max(ans, values[i] - i + max_prev);
            max_prev = max(max_prev, values[i] + i);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1014_H
