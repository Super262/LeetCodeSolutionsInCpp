//
// Created by Fengwei Zhang on 10/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0327_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0327_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem0327 {
    // 原题目转化：Si - upper <= Sj <= Si - lower（S是前缀和数组，0 <= j <= i - 1），寻找(i, j)的个数
    // 也就是F(Si - lower) - F(Si - upper - 1)的值（F是树状数组的前缀和函数）
    // 使用离散化和树状数组来替代平衡树
private:
    int lowBit(const int x) {
        return x & -x;
    }

    int prefixSum(const int idx, const int ft[]) {
        int result = 0;
        for (int i = idx; i > 0; i -= lowBit(i)) {
            result += ft[i];
        }
        return result;
    }

    void updateItem(const int idx, const int val, const int n, int ft[]) {
        for (int i = idx; i <= n; i += lowBit(i)) {
            ft[i] += val;
        }
    }

    int getNumIdx(const long long x, const vector<long long> &numbers) {  // 注意：做差后要加1（树状数组的索引从1开始）
        return (int) (lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin() + 1);
    }

public:
    int countRangeSum(const vector<int> &nums, const int lower, const int upper) {
        const int n = (int) nums.size();
        vector<long long> numbers(1, 0);  // 保存离散化数据的数组0号位为0，真正的数据从1号开始
        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + nums[i - 1];
            numbers.emplace_back(s[i]);
            numbers.emplace_back(s[i] - lower);
            numbers.emplace_back(s[i] - upper - 1);
        }

        // 保序离散化的模版
        sort(numbers.begin(), numbers.end());
        numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

        const int m = (int) numbers.size();
        int ft[m + 1];
        memset(ft, 0, sizeof ft);  // 必须初始化为0
        updateItem(getNumIdx(0, numbers), 1, m, ft);  // 树状数组初始包含S0

        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result += prefixSum(getNumIdx(s[i] - lower, numbers), ft) -
                      prefixSum(getNumIdx(s[i] - upper - 1, numbers), ft);
            updateItem(getNumIdx(s[i], numbers), 1, m, ft);  // 这里被插入的Si会作为后续的Sj
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0327_H
