//
// Created by Fengwei Zhang on 2/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0658_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0658_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 原数组有序，所以我们可以二分（lower_bound）找到最接近x的元素arr[it]；然后，我们从it开始向左、右两侧扩展
    // 初始时l=it-1，r=it+1，我们分别左移l、右移r，直到r-l-1=k，或l、r抵达边界；arr[l+1,r-1]就是答案
public:
    vector<int> findClosestElements(const vector<int> &arr, const int k, const int x) {
        // 2个特殊情况：x比起点小、x比终点大
        if (x <= *arr.begin()) {
            return {arr.begin(), arr.begin() + k};
        }
        const auto n = (int) arr.size();
        if (x >= *(arr.begin() + (n - 1))) {
            return {arr.begin() + (n - k), arr.end()};
        }
        // 找到第一个大于或等于x的位置
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
