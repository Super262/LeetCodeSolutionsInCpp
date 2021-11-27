//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0423_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0423_H

#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 找规律，观察每个单词中的特异字母和每个单词间的重叠字母，归纳出搜索顺序
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
        string res;
        for (int i = 0; i < 10; ++i) {
            while (counter[i] > 0) {
                res += to_string(i);
                --counter[i];
            }
        }
        return res;
    }

private:
    bool digitExists(int freq[], const string &d) {
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
