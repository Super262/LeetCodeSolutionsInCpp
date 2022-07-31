//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0783_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0783_H

#include <algorithm>
#include "treenode.h"

using namespace std;

class Problem0783 {
    // BST中序是有序的，所以最小差值一定出现在中序序列的相邻元素之间
    // 因此，我们采取中序遍历，记录当前点root和上个点prev的差值，适时更新答案
    // 同LeetCode 530
public:
    int minDiffInBST(TreeNode *root) {
        int prev = 0x3f3f3f3f;
        int answer = 0x3f3f3f3f;
        dfs(root, prev, answer);
        return answer;
    }

private:
    void dfs(TreeNode *root, int &prev, int &answer) {
        if (!root) {
            return;
        }
        dfs(root->left, prev, answer);
        answer = min(abs(root->val - prev), answer);
        prev = root->val;
        dfs(root->right, prev, answer);
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0783_H
