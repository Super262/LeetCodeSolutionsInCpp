//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0068_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0068_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 最后一行：左对齐
    // 只包含一个单词：左对齐
    // 其他：左右对齐
public:
    vector<string> fullJustify(const vector<string> &words, const int max_width) {
        vector<string> res;
        for (int i = 0; i < (int) words.size(); ++i) {
            auto j = i + 1;  // words[j - 1]指示当前行的终点单词
            auto str_len = (int) words[i].size();  // str首单词是words[i]

            // 尝试加入1个前导空格和新单词，求当前最大可行长度
            while (j < (int) words.size() && str_len + 1 + (int) words[j].size() <= max_width) {
                str_len += 1 + (int) words[j].size();
                ++j;
            }

            string line;
            if (j == i + 1 || j == (int) words.size()) {  // 当前行只包含1个单词或是最后1行
                line += words[i];
                for (int k = i + 1; k < j; ++k) {
                    line.push_back(' ');  // 左对齐：每个前单词只有1个空格
                    line += words[k];
                }
                while (line.size() < max_width) {
                    line.push_back(' ');
                }
            } else {
                auto blank_cnt = j - i - 1;  // 空白区域个数
                // 需要添加的空格数（不要忘记加上blank_cnt：str_len包含blank_cnt个前导空格）
                auto space_cnt = max_width - str_len + blank_cnt;
                int k = 1;
                line += words[i];
                while (k <= space_cnt % blank_cnt) {  // 左边的空白区域空格数更多
                    line += string(space_cnt / blank_cnt + 1, ' ');
                    line += words[i + k];
                    ++k;
                }
                while (k <= blank_cnt) {
                    line += string(space_cnt / blank_cnt, ' ');
                    line += words[i + k];
                    ++k;
                }
            }
            res.emplace_back(line);
            i = j - 1;
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0068_H
