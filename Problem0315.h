//
// Created by Fengwei Zhang on 10/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0315_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0315_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0315 {
public:
    int lowBit(const int x) {
        return x & -x;
    }

    void updateItem(const int idx, const int n, int ft[], const int val) {
        for (int i = idx; i <= n; i += lowBit(i)) {
            ft[i] += val;
        }
    }

    int prefixSum(const int idx, const int ft[]) {
        int result = 0;
        for (int i = idx; i > 0; i -= lowBit(i)) {
            result += ft[i];
        }
        return result;
    }

    vector<int> countSmaller(const vector<int> &nums) {
        int maximal = nums[0];
        int minimal = nums[0];
        for (auto x: nums) {
            if (x > maximal) {
                maximal = x;
            }
            if (x < minimal) {
                minimal = x;
            }
        }

        int offset = 0;
        if (minimal <= 0) { // 需要设置偏移量使idx > 0恒成立；否则，出现死循环
            offset = -minimal + 1;  // 必须保证：offset + minimal > 0
        }

        int ft[maximal + offset + 1];
        memset(ft, 0, sizeof ft);
        vector<int> result(nums.size(), 0);
        for (int i = (int) nums.size() - 1; i >= 0; --i) {
            result[i] = prefixSum(nums[i] + offset - 1, ft);
            updateItem(nums[i] + offset, maximal + offset, ft, 1);
        }

        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0315_H
