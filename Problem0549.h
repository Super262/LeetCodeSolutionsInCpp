//
// Created by Fengwei Zhang on 6/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0549_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0549_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Solution {
    // 类似后序遍历，先得到子树的结果对，再根据根的值，确定返回值；设置全局变量ans存储答案
    // 每次遍历，返回以u为终点的升序序列、降序序列的长度
public:
    int longestConsecutive(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int ans = 1;
        dfs(root, ans);
        return ans;
    }

private:
    pair<int, int> dfs(TreeNode *u, int &ans) {
        pair<int, int> lp = {0, 0};
        pair<int, int> rp = {0, 0};
        pair<int, int> cur = {1, 1};
        if (u->left) {
            lp = dfs(u->left, ans);
            if (u->val == u->left->val + 1) {
                cur.first = max(cur.first, 1 + lp.first);
            } else if (u->val == u->left->val - 1) {
                cur.second = max(cur.second, 1 + lp.second);
            }
        }
        if (u->right) {
            rp = dfs(u->right, ans);
            if (u->val == u->right->val + 1) {
                cur.first = max(cur.first, 1 + rp.first);
            } else if (u->val == u->right->val - 1) {
                cur.second = max(cur.second, 1 + rp.second);
            }
        }
        ans = max(ans, cur.first + cur.second - 1);
        return cur;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0549_H
