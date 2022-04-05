//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0836_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0836_H

#include <vector>

using namespace std;

class Solution {
    // 判断rec1在坐标轴的投影l1和rec2在坐标轴的投影l2是否有交集
public:
    bool isRectangleOverlap(const vector<int> &rec1, const vector<int> &rec2) {
        return checkProjection(rec1[0], rec1[2], rec2[0], rec2[2]) &&
               checkProjection(rec1[1], rec1[3], rec2[1], rec2[3]);
    }

private:
    bool checkProjection(int s1, int e1, int s2, int e2) {  // 投影为[s:e]
        if (s1 >= e1 || s2 >= e2) {  // 矩形的投影长度应大于0
            return false;
        }
        return e1 > s2 && e2 > s1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0836_H
