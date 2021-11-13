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
        vector<string> result;
        if (s.size() <= 10) {  // 注意边界情况
            return result;
        }
        unordered_map<string, int> strCount;
        int l = 0;
        int r = 9;
        while (r < (int) s.size()) {
            ++strCount[s.substr(l, r - l + 1)];
            ++l;
            ++r;
        }
        for (const auto &item: strCount) {
            if (item.second <= 1) {
                continue;
            }
            result.emplace_back(item.first);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0187_H
