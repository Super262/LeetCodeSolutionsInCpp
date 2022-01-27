//
// Created by Fengwei Zhang on 1/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0553_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0553_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 脑筋急转弯：为[1:n-1]段加括号
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
        string res = to_string(nums[0]);
        res.push_back('/');
        res.push_back('(');
        res.append(to_string(nums[1]));
        for (int i = 2; i < n; ++i) {
            res.push_back('/');
            res.append(to_string(nums[i]));
        }
        res.push_back(')');
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0553_H
