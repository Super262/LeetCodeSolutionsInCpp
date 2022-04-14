//
// Created by Fengwei Zhang on 4/13/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0916_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0916_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // max_cnt2[ch]：字符ch在words2的单词中的最大频率；枚举words1的每个单词，统计字符频率是否大于max_cnt2
public:
    vector<string> wordSubsets(const vector<string> &words1, const vector<string> &words2) {
        unordered_map<char, int> max_cnt2;
        unordered_map<char, int> temp;
        for (const auto &s: words2) {
            temp.clear();
            for (const auto &ch: s) {
                ++temp[ch];
            }
            for (const auto &item: temp) {
                max_cnt2[item.first] = max(max_cnt2[item.first], item.second);
            }
        }
        vector<string> ans;
        for (const auto &s: words1) {
            temp.clear();
            for (const auto &ch: s) {
                ++temp[ch];
            }
            bool is_sub = true;
            for (const auto &item: max_cnt2) {
                if (!temp.count(item.first) || temp[item.first] < item.second) {
                    is_sub = false;
                    break;
                }
            }
            if (is_sub) {
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0916_H
