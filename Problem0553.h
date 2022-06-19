//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0553_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0553_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 贪心算法：设输入序列长度为n，将num[1:n-1]括出时，表达式的值最大
    // 举例，设nums=[1,2,3,4]，最大值对应的表达式是"1/(2/3/4)"
public:
    string optimalDivision(const vector<int> &nums) {
        const auto n = (int) nums.size();
        if (n == 0) {
            return "";
        }
        if (n == 1) {
            return to_string(nums[0]);
        }
        if (n == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        string ans = to_string(nums[0]);
        ans += '/';
        ans += '(';
        ans.append(to_string(nums[1]));
        for (int i = 2; i < n; ++i) {
            ans += '/';
            ans.append(to_string(nums[i]));
        }
        ans += ')';
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0553_H
