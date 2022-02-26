
//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0761_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0761_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 贪心算法 + 递归处理：https://www.acwing.com/solution/content/3594/
public:
    string makeLargestSpecial(const string &s) {
        if (s.size() <= 2) {
            return s;
        }
        vector<string> parts;
        string temp;
        int counter = 0;
        for (const auto &ch: s) {
            temp += ch;
            counter += ch == '1' ? 1 : -1;
            if (!counter) {
                parts.emplace_back("1" + makeLargestSpecial(temp.substr(1, temp.size() - 2)) + "0");
                temp.clear();
            }
        }
        sort(parts.begin(), parts.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        string res;
        for (const auto &t: parts) {
            res += t;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0761_H
