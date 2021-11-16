//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0278_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0278_H

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0278_H
