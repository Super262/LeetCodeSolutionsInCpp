//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0492_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0492_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
    // 设area=x^2，我们从大到小、遍历所有可能的W，W的初值为x；若发现可行的W（area%W=0），返回{area/W,W}
public:
    vector<int> constructRectangle(const int area) {
        for (auto w = (int) sqrt(area); w >= 1; --w) {
            if (area % w) {
                continue;
            }
            return {area / w, w};
        }
        return {area, 1};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0492_H
