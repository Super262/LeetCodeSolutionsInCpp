//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0105_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0105_H

#include <unordered_map>
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

class Problem0105 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> inOrderPos;
        for (int i = 0; i < (int) inorder.size(); ++i) {
            inOrderPos[inorder[i]] = i;
        }
        return helper(preorder, inorder, inOrderPos, 0, (int) preorder.size() - 1, 0, (int) inorder.size() - 1);
    }

    TreeNode *helper(const vector<int> &preorder, const vector<int> &inorder, const unordered_map<int, int> &inOrderPos,
                     const int &pl, const int &pr, const int &il, const int &ir) {
        if (il > ir) {
            return NULL;
        }
        auto root = new TreeNode(preorder[pl]);
        auto mid = inOrderPos.find(preorder[pl])->second;
        root->left = helper(preorder, inorder, inOrderPos, pl + 1, pl + mid - il, il, mid - 1);
        root->right = helper(preorder, inorder, inOrderPos, pr - (ir - mid) + 1, pr, mid + 1, ir);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0105_H
