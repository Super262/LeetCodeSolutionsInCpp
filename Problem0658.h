//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0658_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0658_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 经典算法，必须掌握：二分查找 + 双指针
    // https://leetcode-cn.com/problems/find-k-closest-elements/solution/zhao-dao-kge-zui-jie-jin-de-yuan-su-by-leetcode/
public:
    vector<int> findClosestElements(const vector<int> &arr, const int k, const int x) {
        // 2个特殊情况：x比起点小、x比终点大
        if (x <= *arr.begin()) {
            return {arr.begin(), arr.begin() + k};
        }
        const auto n = (int) arr.size();
        if (x >= *(arr.begin() + n - 1)) {
            return {arr.begin() + n - k, arr.end()};
        }
        // 找到第一个大于x的位置
        auto it = (int) (lower_bound(arr.begin(), arr.end(), x) - arr.begin());
        // 在(l:r)中搜索，r的位置是it的位置
        auto l = max(it - 1, -1);
        auto r = min(n, it);
        while (r - l - 1 < k) {
            if (l < 0) {  // l已抵达下限
                ++r;
                continue;
            }
            if (r >= n) {  // r已抵达上限
                --l;
                continue;
            }
            if (abs(x - arr[l]) <= abs(x - arr[r])) {  // l更接近且l更小，扩展左部
                --l;
            } else {  // 扩展右部
                ++r;
            }
        }
        return {arr.begin() + max(l + 1, 0), arr.begin() + min(n, r)};  // 防止越界
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0658_H
