//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0949_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0949_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // 遍历arr的所有排列，寻找最大值
public:
    string largestTimeFromDigits(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int rh = -1;  // 结果的小时部分
        int rm = -1;  // 结果的分钟部分
        do {
            auto h = arr[0] * 10 + arr[1];
            auto m = arr[2] * 10 + arr[3];
            if (h >= 24 || m >= 60) {
                continue;
            }
            if (h > rh) {
                rh = h;
                rm = m;
            } else if (h == rh) {
                rm = max(rm, m);
            }
        } while (next_permutation(arr.begin(), arr.end()));
        if (rh == -1 && rm == -1) {
            return "";
        }
        string sh;  // 小时的字符串表示
        string sm;  // 分钟的字符串表示
        if (rh < 10) {  // 补齐前导0
            sh += '0';
        }
        if (rm < 10) {
            sm += '0';
        }
        sh += to_string(rh);
        sm += to_string(rm);
        return sh + ':' + sm;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0949_H
