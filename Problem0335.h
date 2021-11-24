//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0335_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0335_H

#include <vector>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/362/
public:
    bool isSelfCrossing(const vector<int> &distance) {
        const int n = (int) distance.size();
        if (n < 4) {
            return false;
        }
        for (int i = 3; i < n; i++) {
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) {
                return true;
            }
            if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) {
                return true;
            }
            if (i >= 5 && x[i - 2] >= x[i - 4] && x[i] + x[i - 4] >= x[i - 2] && x[i - 1] + x[i - 5] >= x[i - 3] &&
                x[i - 1] <= x[i - 3]) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0335_H
