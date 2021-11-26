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
        int currentLength = 0;  // 当前所有目录名、文件名长度之和
        stack<int> levelStk;  // 保存所有层级的单调上升栈
        stack<int> lengthStk; // 保存每个层级对应的文件名或目录名的长度
        int i = 0;
        while (i < (int) input.size()) {
            auto level = getNextLevel(input, i);  // 根据开头的"\t"数量确定层级
            auto name = getNextName(input, i);  // 获取文件名
            while (!levelStk.empty() && levelStk.top() >= level) {
                currentLength -= lengthStk.top();
                levelStk.pop();
                lengthStk.pop();
            }
            levelStk.push(level);
            lengthStk.push((int) name.size());
            currentLength += (int) name.size();
            if (isFile(name)) {
                result = max(result, currentLength + level);
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
