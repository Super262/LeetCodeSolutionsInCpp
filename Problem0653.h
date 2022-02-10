//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0653_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0653_H

#include <unordered_set>

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
    // 经典算法，直接背诵：中序遍历
public:
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> nums;
        return dfs(root, k, nums);
    }

private:
    bool dfs(TreeNode *root, int k, unordered_set<int> &nums) {  // 中序遍历，保证有序性
        if (!root) {
            return false;
        }
        if (dfs(root->left, k, nums)) {
            return true;
        }
        if (nums.count(k - root->val)) {
            return true;
        }
        nums.insert(root->val);
        return dfs(root->right, k, nums);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0653_H
