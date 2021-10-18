//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0336_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0336_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Problem0336 {
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

public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        unordered_map<string, int> reversedIdx;  // 保存反转后的key的索引
        for (int i = 0; i < (int) words.size(); ++i) {
            reversedIdx[string(words[i].rbegin(), words[i].rend())] = i;
        }
        vector<vector<int>> result;
        for (int i = 0; i < (int) words.size(); ++i) {
            const auto &w = words[i];
            for (int l = 0; l <= (int) w.size(); ++l) {
                auto leftPart = w.substr(0, l);
                auto rightPart = w.substr(l);
                if (isPalindrome(rightPart) && reversedIdx.count(leftPart) && reversedIdx[leftPart] != i) {
                    // 尝试构建(leftPart + rightPart + reverse(leftPart))为回文字符串
                    // 注意：reverse(leftPart)不能等于leftPart，因为题目要求由2个单词构建字符串
                    result.push_back({i, reversedIdx[leftPart]});
                }
                if (isPalindrome(leftPart) && reversedIdx.count(rightPart) && reversedIdx[rightPart] != i &&
                    w.size() != words[reversedIdx[rightPart]].size()) {
                    // 尝试构建(reverse(rightPart) + leftPart + rightPart)为回文字符串
                    // 注意：reverse(rightPart)不能等于rightPart，因为题目要求由2个单词构建字符串
                    // 同时：避免重复加入(reverse(w) + w)的情况（即leftPart == ""）
                    result.push_back({reversedIdx[rightPart], i});
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0336_H
