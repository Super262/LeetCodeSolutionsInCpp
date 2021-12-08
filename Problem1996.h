//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1996_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1996_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 贪心思想，巧妙排序：若defense比之前小，说明attack也比之前小
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] > b[0]) {  // 攻击值从大到小
                return true;
            }
            if (a[0] < b[0]) {
                return false;
            }
            return a[1] < b[1];  // 防御值从小到大
        });
        int result = 0;
        auto pre_max_defense = properties[0][1];
        for (int i = 1; i < properties.size(); ++i) {
            if (properties[i][1] >= pre_max_defense) {
                pre_max_defense = properties[i][1];
            } else {
                ++result;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1996_H
