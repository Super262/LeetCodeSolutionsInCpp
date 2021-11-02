//
// Created by Fengwei Zhang on 11/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0106_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0106_H

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

class Problem0106 {
public:
    TreeNode *buildTree(const vector<int> &inorder, const vector<int> &postorder) {
        unordered_map<int, int> inOrderPos;
        for (int i = 0; i < (int) inorder.size(); ++i) {
            inOrderPos[inorder[i]] = i;
        }
        return helper(postorder, inorder, inOrderPos, 0, (int) postorder.size() - 1, 0, (int) inorder.size() - 1);
    }

    TreeNode *
    helper(const vector<int> &postorder,
           const vector<int> &inorder,
           const unordered_map<int, int> &inOrderPos,
           const int &pl,
           const int &pr,
           const int &il,
           const int &ir) {
        if (il > ir) {
            return NULL;
        }
        auto root = new TreeNode(postorder[pr]);
        auto imid = inOrderPos.find(postorder[pr])->second;
        root->left = helper(postorder, inorder, inOrderPos, pl, pl + (imid - il) - 1, il, imid - 1);
        root->right = helper(postorder, inorder, inOrderPos, pl + (imid - il), pr - 1, imid + 1, ir);
        return root;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0106_H
