//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0492_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0492_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(const int area) {
        for (auto a = (int) sqrt(area); a >= 1; --a) {
            if (area % a) {
                continue;
            }
            return {area / a, a};
        }
        return {area, 1};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0492_H
