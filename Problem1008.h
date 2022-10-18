//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1008_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1008_H

#include <vector>
#include "treenode.h"

using namespace std;

class Problem1008 {
    // 二分查找左右子树的分界线，递归构造BST，类似先序遍历
public:
    TreeNode *bstFromPreorder(const vector<int> &preorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        return buildTree(0, (int) preorder.size() - 1, preorder);
    }

private:
    TreeNode *buildTree(int st, int ed, const vector<int> &preorder) {
        auto root = new TreeNode(preorder[st]);
        auto l = st;
        auto r = ed;
        while (l < r) {  // 查找左子树的终点
            auto mid = l + (r - l + 1) / 2;
            if (preorder[mid] < root->val) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        auto rst = l + 1;
        // 注意边界的合法性判断：子树长度大于0，子树的起点索引应大于根的索引
        if (rst - 1 >= st + 1 && rst - 1 <= ed) {
            root->left = buildTree(st + 1, rst - 1, preorder);
        }
        if (rst > st && rst <= ed) {
            root->right = buildTree(rst, ed, preorder);
        }
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1008_H
