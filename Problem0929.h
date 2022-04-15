//
// Created by Fengwei Zhang on 4/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0929_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0929_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    // 任意地址"a@b"，归一化a部分，统计不同地址的数量
public:
    int numUniqueEmails(const vector<string> &emails) {
        unordered_set<string> s;
        for (const auto &e: emails) {
            auto k = e.find_first_of('@');
            string t;
            for (int i = 0; i < k; ++i) {
                if (e[i] == '+') {
                    break;
                }
                if (e[i] == '.') {
                    continue;
                }
                t += e[i];
            }
            t += '@';
            t += e.substr(k + 1);
            s.insert(t);
        }
        return (int) s.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0929_H
