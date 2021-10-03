//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0068_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0068_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0068 {
    // 最后一行：左对齐
    // 只包含一个单词：左对齐
    // 其他：左右对齐
private:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result;
        for (int i = 0; i < (int) words.size(); ++i) {
            auto j = i + 1;  // words[j - 1]指示当前行的终点单词
            auto strLen = (int) words[i].size();  // str首单词是words[i]

            // 尝试加入前导空格和新单词，求得最大可行长度
            while (j < (int) words.size() && strLen + 1 + (int) words[j].size() <= maxWidth) {
                strLen += 1 + (int) words[j].size();
                ++j;
            }

            string line;
            if (j == i + 1 || j == (int) words.size()) {  // 当前行只包含1个单词或是最后1行
                line += words[i];
                for (int k = i + 1; k < j; ++k) {
                    line.push_back(' ');  // 左对齐：每个前单词只有1个空格
                    line += words[k];
                }
                while (line.size() < maxWidth) {
                    line.push_back(' ');
                }
            } else {
                auto blanksCount = j - i - 1;  // 空白区域个数
                // 需要添加的空格数（不要忘记加上blanksCount：strLen包含blanksCount）
                auto spacesCount = maxWidth - strLen + blanksCount;
                int k = 1;
                line += words[i];
                while (k <= spacesCount % blanksCount) {  // 左边的空白区域空格数更多
                    line += string(spacesCount / blanksCount + 1, ' ');
                    line += words[i + k];
                    ++k;
                }
                while (k <= blanksCount) {
                    line += string(spacesCount / blanksCount, ' ');
                    line += words[i + k];
                    ++k;
                }

            }
            result.emplace_back(line);
            i = j - 1;

        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0068_H
