//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0530_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0530_H

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
    int getMinimumDifference(TreeNode *root) {
        int answer = INF;
        dfs(root, answer);
        return answer;
    }

private:
    pair<int, int> dfs(TreeNode *root, int &answer) {
        if (!root) {
            return {INF, -INF};
        }
        auto l_p = dfs(root->left, answer);
        auto r_p = dfs(root->right, answer);
        answer = min(answer, min(abs(root->val - l_p.second), abs(r_p.first - root->val)));
        return {min(l_p.first, root->val), max(r_p.second, root->val)};
    }

    const int INF = 0x3f3f3f3f;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0530_H
