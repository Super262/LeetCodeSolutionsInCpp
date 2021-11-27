//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0414_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0414_H

#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(const vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        long long a = INT_MIN - 1ll;
        long long b = INT_MIN - 1ll;
        long long c = INT_MIN - 1ll;
        int uniqueCnt = 0;
        for (int x: nums) {
            if (x > a) {
                c = b;
                b = a;
                a = x;
                ++uniqueCnt;
            } else if (x < a && x > b) {
                c = b;
                b = x;
                ++uniqueCnt;
            } else if (x < b && x > c) {
                c = x;
                ++uniqueCnt;
            }
        }
        if (uniqueCnt < 3) {
            return (int) a;
        }
        return (int) c;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0414_H
