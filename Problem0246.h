//
// Created by Fengwei Zhang on 11/15/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0246_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0246_H

#include <string>

using namespace std;

class Solution {
    // 判断num是否中心对称：双指针，从边界向中心检查
    // 根据常识，"2"、"3"、"4"、"5"、"7"是不合要求的
public:
    bool isStrobogrammatic(const string &num) {
        int l = 0;
        auto r = (int) num.size() - 1;
        while (l <= r) {  // l<=r，因为num最小长度为1
            if (num[l] == '0') {  // "0" 对应 "0"
                if (num[r] != '0') {
                    return false;
                }
            } else if (num[l] == '1') {  // "1" 对应 "1"
                if (num[r] != '1') {
                    return false;
                }
            } else if (num[l] == '6') {  // "6" 对应 "9"
                if (num[r] != '9') {
                    return false;
                }
            } else if (num[l] == '8') {  // "8" 对应 "8"
                if (num[r] != '8') {
                    return false;
                }
            } else if (num[l] == '9') { // "9" 对应 "6"
                if (num[r] != '6') {
                    return false;
                }
            } else {  // 出现"2"、"3"、"4"、"5"、"7"
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0246_H
