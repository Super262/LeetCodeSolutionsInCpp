//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0722_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0722_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 经典算法，直接背诵
public:
    vector<string> removeComments(const vector<string> &source) {
        string str;
        for (const auto &s: source) {
            str += s;
            str += '\n';
        }
        vector<string> res;
        string line;
        int i = 0;
        while (i < str.size()) {
            if (i + 1 < str.size() && str[i] == '/' && str[i + 1] == '/') {  // 行注释
                while (str[i] != '\n') {
                    ++i;
                }
            } else if (i + 1 < str.size() && str[i] == '/' && str[i + 1] == '*') {
                i += 2;
                while (str[i] != '*' || str[i + 1] != '/') {
                    ++i;
                }
                i += 2;
            } else if (str[i] == '\n') {
                if (!line.empty()) {
                    res.emplace_back(line);
                    line.clear();
                }
                ++i;
            } else {
                line += str[i];
                ++i;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0722_H
