//
// Created by Fengwei Zhang on 1/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0563_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0563_H

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
public:
    int findTilt(TreeNode *root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }

private:
    int dfs(TreeNode *root, int &answer) {
        if (!root) {
            return 0;
        }
        auto ls = dfs(root->left, answer);
        auto rs = dfs(root->right, answer);
        answer += abs(ls - rs);
        return ls + rs + root->val;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0563_H
