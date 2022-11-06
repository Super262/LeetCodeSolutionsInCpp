//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0108_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0108_H

#include <vector>
#include "treenode.h"

using namespace std;

class Problem0108 {
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
