//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0137_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0137_H

#include <vector>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/232/
public:
    int singleNumber(const vector<int> &nums) {
        int answer = 0;
        for (int offset = 0; offset < 32; ++offset) {
            int ones = 0;
            for (const auto &num: nums) {
                if ((num >> offset) & 1) {
                    ++ones;
                }
            }
            answer += (ones % 3) << offset;
        }
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0137_H
