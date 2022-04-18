//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0967_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0967_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
    // 直接爆搜：当前位为x，下一位为x-k或x+k
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        const auto minimal = (int) pow(10, n - 1);
        const auto maximal = (int) pow(10, n) - 1;
        vector<int> ans;
        for (int d = 1; d <= 9; ++d) {
            dfs(d, k, minimal, maximal, ans);
        }
        return ans;
    }

private:
    void dfs(int num, const int k, const int minimal, const int maximal, vector<int> &ans) {
        if (num >= minimal && num <= maximal) {  // num是n位数，合法
            ans.emplace_back(num);
            return;
        }
        if (num > maximal) {  // num是n+1位数，非法
            return;
        }
        auto d = num % 10;  // 取出当前最低位
        if (!k) {  // 特判k==0，否则会导致答案重复
            dfs(num * 10 + d, k, minimal, maximal, ans);
            return;
        }
        if (d - k >= 0 && d - k <= 9) {
            dfs(num * 10 + (d - k), k, minimal, maximal, ans);
        }
        if (d + k >= 0 && d + k <= 9) {
            dfs(num * 10 + (d + k), k, minimal, maximal, ans);
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0967_H
