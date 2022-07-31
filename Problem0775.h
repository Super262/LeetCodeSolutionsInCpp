//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0775_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0775_H

#include <cmath>
#include <vector>

using namespace std;

class Problem0775 {
    // 数学：假设下标从0开始，任意的A[i]与i的距离都不超过1，则全局倒置与局部倒置相等
    // 反证：假设存在i、j，满足A[i]>A[j]，且i+1<j；那么，A[i]+j>A[j]+i+1，A[i]-i>A[j]-j+1；由于任意A[i]与i的距离不超过1，
    // 我们只能规定A[i]-i=1，A[j]-j=-1；那么，A[i]=i+1<j=A[j]+1，与A[i]>A[j]矛盾
public:
    bool isIdealPermutation(const vector<int> &nums) {
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (abs(i - nums[i]) > 1) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0775_H
