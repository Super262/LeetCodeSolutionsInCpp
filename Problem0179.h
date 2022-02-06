//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0179_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0179_H

#include <string>
#include <vector>

using namespace std;

class Solution {
    // 理解正确性证明（正确比较的3个性质），然后直接背诵！
    // 设计合理的比较函数
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), cmp);
        string result;
        for (const int &x: nums) {
            result += to_string(x);
        }
        // 过滤前导0但又不忽略结果为整数0的情况
        int k = 0;
        while (k + 1 < (int) result.size() && result[k] == '0') {
            ++k;
        }
        return result.substr(k);
    }

private:
    static bool cmp(const int x, const int y) {
        auto a = to_string(x);
        auto b = to_string(y);
        return a + b > b + a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0179_H
