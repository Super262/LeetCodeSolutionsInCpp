//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0273_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0273_H

#include <string>
#include <vector>

using namespace std;

class Solution {
    // 输入的数据范围为[0:2^31)，因此我们首先尝试提取10^9位，以1000位步长：10^9, 10^6, 10^3
public:
    string numberToWords(int num) {
        if (!num) {  // 特殊情况：0
            return "Zero";
        }
        string res;
        for (int i = 1e9, j = 0; i >= 1; i /= 1000, ++j) {  // 根据题目的数据范围，起始基数为10亿
            if (num >= i) {
                res += convert1000(num / i) + (j < 3 ? nums1000[j] + " " : "");
                num %= i;
            }
        }
        res.pop_back();  // 去掉尾部空格
        return res;
    }

private:
    vector<string> nums1To19 = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                "Eighteen", "Nineteen"};
    vector<string> nums20To90 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> nums1000 = {"Billion", "Million", "Thousand"};

    string convert1000(int x) {  // 返回1～999的英文表示
        string res;
        if (x >= 100) {  // 输出百位
            res += nums1To19[x / 100 - 1] + " Hundred ";
            x %= 100;
        }
        if (x >= 20) {  // 输出十位（20或更大）
            res += nums20To90[x / 10 - 2] + " ";
            x %= 10;
        }
        if (x) {  // 输出最低位
            res += nums1To19[x - 1] + " ";
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0273_H
