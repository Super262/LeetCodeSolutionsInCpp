//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0049_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0049_H

#include <string>
#include <vector>

using namespace std;

class Problem0049 {
    // 技巧：对字符串按字典序排序
private:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map <string, vector<string>> dict;
        vector<vector<string>> result;
        for (const auto &s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            dict[key].emplace_back(s);
        }
        for (auto &item: dict) {
            result.emplace_back(item.second);
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0049_H
