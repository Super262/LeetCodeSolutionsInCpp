//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0290_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0290_H

#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    // 检验满射
public:
    bool wordPattern(const string &pattern, const string &s) {
        stringstream ssin(s);
        vector<string> words;
        string temp;
        while (ssin >> temp) {
            words.emplace_back(temp);
        }
        if (words.size() != pattern.size()) {  // 不符合满射的基本要求
            return false;
        }
        unordered_map<string, char> wp;
        unordered_map<char, string> pw;
        for (int i = 0; i < (int) pattern.size(); ++i) {
            if (pw.count(pattern[i]) && pw[pattern[i]] != words[i]) {
                return false;
            }
            pw[pattern[i]] = words[i];
            if (wp.count(words[i]) && wp[words[i]] != pattern[i]) {
                return false;
            }
            wp[words[i]] = pattern[i];
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0290_H
