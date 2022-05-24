//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0336_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0336_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    // 枚举分界点，利用字符串哈希建立映射
public:
    vector<vector<int>> palindromePairs(const vector<string> &words) {
        unsigned long long power[N];
        vector<vector<unsigned long long>> raw_hash_seq(words.size());  // words[i]的哈希序列
        vector<vector<unsigned long long>> reversed_hash_seq(words.size());  // reverse(words[i])的哈希序列
        unordered_map<unsigned long long, int> hash_to_idx; // 哈希值映射到words[i]
        initialize(power, words, raw_hash_seq, reversed_hash_seq, hash_to_idx);
        vector<vector<int>> result;
        for (int i = 0; i < (int) words.size(); ++i) {
            const auto &m = (int) words[i].size();
            for (int j = 0; j <= m; ++j) {
                auto raw_left_hash = j ? getHashValue(raw_hash_seq[i], power, 1, j) : 0;
                auto reversed_left_hash = j ? getHashValue(reversed_hash_seq[i], power, m - j + 1, m) : 0;
                auto raw_right_hash = j != m ? getHashValue(raw_hash_seq[i], power, j + 1, m) : 0;
                auto reversed_right_hash = j != m ? getHashValue(reversed_hash_seq[i], power, 1, m - j) : 0;
                if (raw_right_hash == reversed_right_hash && hash_to_idx.count(reversed_left_hash) &&
                    hash_to_idx[reversed_left_hash] != i) {
                    // 尝试构建(left_part + right_part + reverse(left_part))为回文字符串
                    // 注意：reverse(left_part)不能等于words[i]，因为题目要求由2个不同的单词构建回文
                    result.push_back({i, hash_to_idx[reversed_left_hash]});
                }
                if (raw_left_hash == reversed_left_hash && hash_to_idx.count(reversed_right_hash) &&
                    hash_to_idx[reversed_right_hash] != i && m != words[hash_to_idx[reversed_right_hash]].size()) {
                    // 尝试构建(reverse(right_part) + left_part + right_part)为回文字符串
                    // 注意：reverse(right_part)不能等于words[i]，因为题目要求由2个不同的单词构建字符串
                    // 同时：避免重复加入(reverse(w) + w)的情况（leftPart == ""的情况已被上方的if块处理，应避免重复）
                    result.push_back({hash_to_idx[reversed_right_hash], i});
                }
            }
        }
        return result;
    }

private:
    const unsigned int P = 131;

    const int N = 310;

    void initialize(unsigned long long power[],
                    const vector<string> &words,
                    vector<vector<unsigned long long>> &raw_hash_seq,
                    vector<vector<unsigned long long>> &reversed_hash_seq,
                    unordered_map<unsigned long long, int> &hash_to_idx) const {
        power[0] = 1;
        for (int i = 1; i < N; ++i) {
            power[i] = P * power[i - 1];
        }
        for (int i = 0; i < (int) words.size(); ++i) {
            raw_hash_seq[i].resize(words[i].size() + 1);
            reversed_hash_seq[i].resize(words[i].size() + 1);
            raw_hash_seq[i][0] = 0;
            reversed_hash_seq[i][0] = 0;
            for (int j = 1; j <= (int) words[i].size(); ++j) {
                raw_hash_seq[i][j] = raw_hash_seq[i][j - 1] * P + words[i][j - 1];
            }
            for (int j = 1; j <= (int) words[i].size(); ++j) {
                reversed_hash_seq[i][j] = reversed_hash_seq[i][j - 1] * P + words[i][words[i].size() - j];
            }
            hash_to_idx[raw_hash_seq[i][words[i].size()]] = i;
        }
    }

    static unsigned long long getHashValue(const vector<unsigned long long> &h,
                                           const unsigned long long power[],
                                           int l,
                                           int r) {
        return h[r] - h[l - 1] * power[r - l + 1];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0336_H
