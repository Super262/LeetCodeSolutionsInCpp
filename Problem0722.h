//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0722_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0722_H

#include <vector>
#include <string>

using namespace std;

class Problem0722 {
    // 直接模拟；发现"//"后，直接跳过整行；发现"/*"后，跨行遍历，直到发现终止符"*/"
public:
    vector<string> removeComments(const vector<string> &source) {
        vector<string> ans;
        ans.reserve(source.size());
        int i = 0;
        int j = 0;
        string line;
        while (i < (int) source.size()) {
            if (j < (int) source[i].size() && j + 1 < (int) source[i].size() && source[i][j] == '/' &&
                source[i][j + 1] == '/') {  // 单行注释
                j = (int) source[i].size();  // 直接跳过整行
            } else if (j < (int) source[i].size() && j + 1 < (int) source[i].size() && source[i][j] == '/' &&
                       source[i][j + 1] == '*') {  // 多行注释
                j += 2;  // 跳过起点
                while (i < (int) source.size() && (source[i][j] != '*' || source[i][j + 1] != '/')) {
                    ++j;
                    if (j >= (int) source[i].size()) {
                        ++i;
                        j = 0;
                    }
                }
                j += 2;  // 跳过终点
            } else if (j < (int) source[i].size()) {  // 常规字符
                line += source[i][j];
                ++j;
            }
            if (i < (int) source.size() && j >= (int) source[i].size()) {  // 到达当前行终点
                if (!line.empty()) {  // 保存当前行
                    ans.emplace_back(line);
                    line.clear();
                }
                j = 0;  // 跳转下行
                ++i;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0722_H
