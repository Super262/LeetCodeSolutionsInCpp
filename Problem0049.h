//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0049_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0049_H

#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 技巧：对字符串按字典序排序
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> dict;
        vector<vector<string>> result;
        for (const auto &s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            dict[key].emplace_back(s);
        }
        result.reserve(dict.size());  // 提高效率
        for (auto &item: dict) {
            result.emplace_back(item.second);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0049_H
