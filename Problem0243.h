//
// Created by Fengwei Zhang on 11/14/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0243_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0243_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 贪心算法：只记录最近的出现位置
public:
    int shortestDistance(const vector<string> &dict, const string &w1, const string &w2) {
        int s1 = -1;
        int s2 = -1;
        int result = INT_MAX;
        for (int i = 0; i < (int) dict.size(); ++i) {
            if (dict[i] == w1) {
                s1 = i;
            } else if (dict[i] == w2) {
                s2 = i;
            }
            if (s1 == -1 || s2 == -1) {
                continue;
            }
            result = min(result, abs(s1 - s2));
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0243_H
