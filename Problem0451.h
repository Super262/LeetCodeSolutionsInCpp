//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0451_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0451_H

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    // 熟练使用Lambda表达式
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (const auto &ch: s) {
            ++freq[ch];
        }
        sort(s.begin(), s.end(), [&](char a, char b) {  // [&]表示外部变量以引用方式传入
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            } else {
                return a < b;
            }
        });
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0451_H
