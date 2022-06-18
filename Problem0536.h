//
// Created by Fengwei Zhang on 6/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0536_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0536_H

#include <string>
#include "treenode.h"

using namespace std;

class Solution {
    // 类似先序遍历，首先解析当前数字，保存为根结点；若后面无子节点，即后续字符不存在或后续字符为')'
    // 若当前数字后面有新的子树，即发现'('，继续递归，并保存左子树、右子树
    // 细节：数字可能包含'+'或'-'
public:
    TreeNode *str2tree(const string &s) {
        if (s.empty()) {
            return nullptr;
        }
        int i = 0;
        return dfs(s, i);
    }

private:
    TreeNode *dfs(const string &s, int &i) {
        int val = 0;
        bool is_neg = false;
        while (i < (int) s.size() && s[i] != '(' && s[i] != ')') {
            if (s[i] == '-') {
                is_neg = true;
                ++i;
                continue;
            }
            if (s[i] == '+') {
                ++i;
                continue;
            }
            val = val * 10 + s[i] - '0';
            ++i;
        }
        auto root = new TreeNode(is_neg ? -val : val);
        if (i == (int) s.size() || s[i] == ')') {  // 抵达末尾，直接返回
            return root;
        }
        if (i < (int) s.size() && s[i] == '(') {  // 发现新子树
            ++i;  // 跳过'('
            root->left = dfs(s, i);
            ++i;  // 跳过')'
        }
        if (i < (int) s.size() && s[i] == '(') {  // 发现新子树
            ++i;   // 跳过'('
            root->right = dfs(s, i);
            ++i;   // 跳过')'
        }
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0536_H
