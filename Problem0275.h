//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0275_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0275_H

#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(const vector<int> &citations) {
        const int n = (int) citations.size();
        int l = 0;
        int r = n;
        while (l < r) {  // 二分h指数
            auto mid = l + (r - l + 1) / 2;
            if (citations[n - mid] >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0275_H
