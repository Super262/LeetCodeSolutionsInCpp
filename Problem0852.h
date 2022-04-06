//
// Created by Fengwei Zhang on 4/6/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0852_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0852_H

#include <vector>

using namespace std;

class Solution {
    // 二分搜索
public:
    int peakIndexInMountainArray(const vector<int> &arr) {
        int l = 0;
        auto r = (int) arr.size() - 1;
        while (l < r) {
            auto mid = l + (r - l + 1) / 2;
            if (arr[mid] > arr[mid - 1]) {  // mid偏右，所以(mid-1)不会越界
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0852_H
