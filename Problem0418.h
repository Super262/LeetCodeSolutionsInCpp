//
// Created by Fengwei Zhang on 5/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0418_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0418_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    // 预处理，得到next_word和sentence_cnt；words[i]在行首时，下一行的行首单词是words[next_word[i]]
    // sentence_cnt[i]：words[i]在行首时，本行包含sentence_cnt[i]个句子
    // 依次枚举rows行，统计每行的句子个数
public:
    int wordsTyping(const vector<string> &words, int rows, int cols) {
        const auto n = (int) words.size();
        int sentence_cnt[n];
        int next_word[n];
        memset(sentence_cnt, 0, sizeof sentence_cnt);
        memset(next_word, 0, sizeof next_word);
        for (int i = 0; i < n; ++i) {
            auto j = i;
            auto space_left = cols;
            while ((int) words[j].size() <= space_left) {  // 注意：循环条件是words[j].size() <= space_left
                space_left -= 1 + (int) words[j].size();  // 注意：space_left减少(words[j].size()+1)，包含尾部空格
                ++j;
                if (j == n) {
                    ++sentence_cnt[i];
                    j = 0;
                }
            }
            next_word[i] = j;
        }
        int ans = 0;
        for (int i = 0, j = 0; i < rows; ++i) {
            ans += sentence_cnt[j];
            j = next_word[j];
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0418_H
