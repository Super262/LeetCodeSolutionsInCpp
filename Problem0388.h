//
// Created by Fengwei Zhang on 11/25/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0388_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0388_H

#include <string>
#include <stack>

using namespace std;

class Solution {
    // 2个栈，一个存储每个名字的长度、另一个存储当前名字对应的level；维护记录当前路径长度的变量cur_len
    // level值由"\t"的数量决定，影响路径中分隔符"\"的数量；每次获取下一个目录（文件）的level和名字
    // 如果栈顶的level大于等于当前目录（文件）的level，则栈顶不断出栈，且cur_len减去当前level名字的长度
    // 最后，将当前目录（文件）进栈，更新cur_len。如果当前名字是个文件，则用(cur_len+level)更新答案
    // https://www.acwing.com/solution/content/22347/
public:
    int lengthLongestPath(const string &input) {
        stack<int> level_stk;  // 保存所有层级的单调上升栈
        stack<int> length_stk; // 保存每个层级对应的文件名或目录名的长度
        int cur_len = 0;  // 当前所有目录名、文件名长度之和
        int ans = 0;
        int i = 0;
        while (i < (int) input.size()) {
            auto level = nextLevel(input, i);  // 根据开头的"\t"数量确定层级
            auto name = nextName(input, i);  // 获取文件名
            while (!level_stk.empty() && level_stk.top() >= level) {
                cur_len -= length_stk.top();
                level_stk.pop();
                length_stk.pop();
            }
            level_stk.push(level);
            length_stk.push((int) name.size());
            cur_len += (int) name.size();
            if (isFile(name)) {
                ans = max(ans, cur_len + level);
            }
        }
        return ans;
    }

private:
    int nextLevel(const string &input, int &i) {
        int level = 0;
        while (i < (int) input.size() && (input[i] == '\n' || input[i] == '\t')) {
            if (input[i] == '\t') {
                ++level;
            }
            ++i;
        }
        return level;
    }

    string nextName(const string &input, int &i) {
        string name;
        while (i < (int) input.size() && input[i] != '\n' && input[i] != '\t') {
            name.push_back(input[i]);
            ++i;
        }
        return name;
    }

    bool isFile(const string &s) {
        const auto n = (int) s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '.' && i != n - 1) {
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0388_H
