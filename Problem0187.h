//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0187_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0187_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(const string &s) {
        if (s.size() <= 10) {  // 注意边界情况
            return {};
        }

        unordered_map<string, int> str_count;
        int l = 0;
        int r = 9;
        while (r < (int) s.size()) {  // 滑动窗口，截取所有长度为10的子串
            ++str_count[s.substr(l, r - l + 1)];
            ++l;
            ++r;
        }
        vector<string> result;
        for (const auto &item: str_count) {
            if (item.second <= 1) {
                continue;
            }
            result.emplace_back(item.first);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0187_H
