//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0388_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0388_H

#include <string>
#include <stack>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/22347/
    // level值由"\t"的数量决定，影响路径中分隔符"\"的数量
public:
    int lengthLongestPath(const string &input) {
        int result = 0;
        int cur_len = 0;  // 当前所有目录名、文件名长度之和
        stack<int> level_stk;  // 保存所有层级的单调上升栈
        stack<int> length_stk; // 保存每个层级对应的文件名或目录名的长度
        int i = 0;
        while (i < (int) input.size()) {
            auto level = getNextLevel(input, i);  // 根据开头的"\t"数量确定层级
            auto name = getNextName(input, i);  // 获取文件名
            while (!level_stk.empty() && level_stk.top() >= level) {
                cur_len -= length_stk.top();
                level_stk.pop();
                length_stk.pop();
            }
            level_stk.push(level);
            length_stk.push((int) name.size());
            cur_len += (int) name.size();
            if (isFile(name)) {
                result = max(result, cur_len + level);
            }
        }
        return result;
    }

private:
    int getNextLevel(const string &input, int &i) {
        int level = 0;
        while (i < (int) input.size() && (input[i] == '\n' || input[i] == '\t')) {
            if (input[i] == '\t') {
                ++level;
            }
            ++i;
        }
        return level;
    }

    string getNextName(const string &input, int &i) {
        string name;
        while (i < (int) input.size() && input[i] != '\n' && input[i] != '\t') {
            name.push_back(input[i]);
            ++i;
        }
        return name;
    }

    bool isFile(const string &s) {
        const int n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '.' && i != n - 1) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0388_H
