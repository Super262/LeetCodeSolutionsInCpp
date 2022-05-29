//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0423_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0423_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 找规律，观察每个单词中的"特异"字母和每个单词间的重叠字母，归纳出搜索顺序order
    // 依照order，记录每个数字是否存在，并删去每个数字包含的字母；最后，根据记录输出结果
    // https://www.acwing.com/solution/content/22477/
public:
    string originalDigits(const string &s) {
        const string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        const int order[] = {0, 2, 4, 1, 3, 5, 6, 7, 8, 9};
        int freq[26];
        memset(freq, 0, sizeof freq);
        for (const auto &ch: s) {
            ++freq[ch - 'a'];
        }
        int counter[10];
        memset(counter, 0, sizeof counter);
        for (const auto &idx: order) {
            while (digitExists(freq, digits[idx])) {
                ++counter[idx];
                removeDigit(freq, digits[idx]);
            }
        }
        string ans;
        for (int i = 0; i < 10; ++i) {
            while (counter[i] > 0) {
                ans += to_string(i);
                --counter[i];
            }
        }
        return ans;
    }

private:
    bool digitExists(const int freq[], const string &d) {
        for (const auto &ch: d) {
            if (freq[ch - 'a'] == 0) {
                return false;
            }
        }
        return true;
    }

    void removeDigit(int freq[], const string &d) {
        for (const auto &ch: d) {
            if (freq[ch - 'a'] == 0) {
                continue;
            }
            --freq[ch - 'a'];
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0423_H
