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

class Problem0048 {
    // 若s1、s2同属一组anagram，分别对s1、s2排序，排序后s1==s2成立
public:
    vector<vector<string>> groupAnagrams(const vector<string> &strs) {
        unordered_map<string, vector<string>> anagram;
        for (const auto &s: strs) {
            auto key = s;
            sort(key.begin(), key.end());
            anagram[key].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (const auto &item: anagram) {
            ans.emplace_back(item.second);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0049_H
