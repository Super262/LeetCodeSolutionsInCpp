//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0648_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0648_H

#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
    // 根据题意，我们要将句子s中的每个单词替换为存在于dict中的最短前缀；首先，我们计算出dict中每个单词的哈希值h，将h存入集合S
    // 分割出句子s中每个单词w，枚举前缀终点i；若前缀w[0:i]的哈希值存在于集合S，我们将单词w替换为前缀w[0:i]
public:
    string replaceWords(const vector<string> &dict, const string &s) {
        const int P = 131;
        unordered_set<unsigned long long> hash;
        for (const auto &w: dict) {
            unsigned long long h = 0;
            for (const auto &ch: w) {
                h = h * P + ch;
            }
            hash.insert(h);
        }
        stringstream ssin(s);
        string word;
        string ans;
        while (ssin >> word) {
            unsigned long long h = 0;
            int i;
            for (i = 0; i < (int) word.size(); ++i) {
                h = h * P + word[i];
                if (hash.count(h)) {
                    break;
                }
            }
            ans += word.substr(0, i + 1);
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0648_H
