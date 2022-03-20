//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0336_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0336_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(const vector<string> &words) {
        unordered_map<string, int> reversed_idx;  // 保存反转后的key的索引
        for (int i = 0; i < (int) words.size(); ++i) {
            reversed_idx[string(words[i].rbegin(), words[i].rend())] = i;
        }
        vector<vector<int>> result;
        for (int i = 0; i < (int) words.size(); ++i) {
            const auto &w = words[i];
            for (int l = 0; l <= (int) w.size(); ++l) {
                auto left_part = w.substr(0, l);
                auto right_part = w.substr(l);
                if (isPalindrome(right_part) && reversed_idx.count(left_part) && reversed_idx[left_part] != i) {
                    // 尝试构建(left_part + right_part + reverse(left_part))为回文字符串
                    // 注意：reverse(left_part)不能等于leftPart，因为题目要求由2个单词构建字符串
                    result.push_back({i, reversed_idx[left_part]});
                }
                if (isPalindrome(left_part) && reversed_idx.count(right_part) && reversed_idx[right_part] != i &&
                    w.size() != words[reversed_idx[right_part]].size()) {
                    // 尝试构建(reverse(right_part) + left_part + right_part)为回文字符串
                    // 注意：reverse(right_part)不能等于rightPart，因为题目要求由2个单词构建字符串
                    // 同时：避免重复加入(reverse(w) + w)的情况（即leftPart == ""）
                    result.push_back({reversed_idx[right_part], i});
                }
            }
        }
        return result;
    }

private:
    bool isPalindrome(const string &s) {
        int i = 0, j = (int) s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0336_H
