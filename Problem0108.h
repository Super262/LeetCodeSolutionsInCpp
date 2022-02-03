//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0108_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0108_H

#include <vector>

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
    TreeNode *sortedArrayToBST(const vector<int> &nums) {
        return buildTree(nums, 0, (int) nums.size() - 1);
    }

private:
    TreeNode *buildTree(const vector<int> &nums, const int l, const int r) {
        if (l > r) {
            return nullptr;
        }
        auto mid = l + (r - l) / 2;
        auto root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, l, mid - 1);
        root->right = buildTree(nums, mid + 1, r);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0108_H
