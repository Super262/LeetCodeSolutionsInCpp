//
// Created by Fengwei Zhang on 11/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0312_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0312_H

#include <vector>
#include <cstring>

using namespace std;

class Solution {
    // f[st][ed]：打碎 balls[st+1:ed-1] 后的最大价值
    // 区间DP，为简化对边界（0，n-1）的处理，我们拷贝输入、在开头和结尾添加"1"
public:
    int maxCoins(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int balls[n + 2];
        copy(nums.begin(), nums.end(), balls + 1);  // 拷贝原数据
        balls[0] = 1;
        balls[n + 1] = 1;  // 开头和结尾补充1
        int f[n + 2][n + 2];
        memset(f, 0, sizeof f);
        for (int len = 3; len <= n + 2; ++len) {  // 细节：区间最长为n+2
            for (int st = 0; st + len - 1 < n + 2; ++st) {
                const auto ed = st + len - 1;
                for (int mid = st + 1; mid < ed; ++mid) {
                    f[st][ed] = max(f[st][ed], balls[st] * balls[mid] * balls[ed] + f[st][mid] + f[mid][ed]);
                }
            }
        }
        return f[0][n + 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0312_H
