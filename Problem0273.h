//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0273_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0273_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {  // 特殊情况：0
            return "Zero";
        }
        string res;
        for (int i = 1e9, j = 0; i >= 1; i /= 1000, ++j) {  // 根据题目的数据范围，起始基数为10亿
            if (num >= i) {
                res += convert1000(num / i) + (j < 3 ? nums_thousand[j] + " " : "");
                num %= i;
            }
        }
        res.pop_back();  // 去掉尾部空格
        return res;
    }

private:
    vector<string> nums_nineteen = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                    "Eighteen", "Nineteen"};
    vector<string> nums_ninety = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> nums_thousand = {"Billion", "Million", "Thousand"};

    string convert1000(int x) {  // 返回1～999的英文表示
        string res;
        if (x >= 100) {
            res += nums_nineteen[x / 100 - 1] + " Hundred ";
            x %= 100;
        }
        if (x >= 20) {
            res += nums_ninety[x / 10 - 2] + " ";
            x %= 10;
        }
        if (x) {
            res += nums_nineteen[x - 1] + " ";
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0273_H
