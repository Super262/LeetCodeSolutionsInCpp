//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0783_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0783_H

#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // BST中序是有序的，所以结果一定出现在中序序列的相邻元素之间
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
