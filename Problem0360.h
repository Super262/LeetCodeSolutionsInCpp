//
// Created by Fengwei Zhang on 5/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0360_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0360_H

#include <vector>

using namespace std;

class Solution {
    // 二次函数的性质：若a>0，x轴两端对应的y较大，中间部分对应的y较小；若a<0，x轴两端对应的y较小，中间部分对应的y较大
    // 因此，我们可以用双指针从nums头部和尾部分别选取元素；a>=0时，将较大元素加入结果尾部；a<0时，将较小元素加入结果头部
public:
    vector<int> sortTransformedArray(const vector<int> &nums, int a, int b, int c) {
        if (nums.empty()) {
            return {};
        }
        const auto n = (int) nums.size();
        vector<int> ans(n, 0);
        int l = 0;
        auto r = n - 1;
        int i = a >= 0 ? n - 1 : 0;
        while (l <= r) {
            auto p = fx(nums[l], a, b, c);
            auto q = fx(nums[r], a, b, c);
            if (a >= 0) {
                if (p >= q) {
                    ans[i] = p;
                    ++l;
                } else {
                    ans[i] = q;
                    --r;
                }
                --i;
            } else {
                if (p >= q) {
                    ans[i] = q;
                    --r;
                } else {
                    ans[i] = p;
                    ++l;
                }
                ++i;
            }
        }
        return ans;
    }

private:
    int fx(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0360_H
