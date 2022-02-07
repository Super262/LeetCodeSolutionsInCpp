//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0199_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0199_H

#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode *root) {
        // 层序遍历，保存最右侧的点
        vector<int> result;
        if (!root) {
            return result;
        }
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto length = (int) q.size();
            while (length--) {
                auto rn = q.front();
                q.pop();
                if (rn->left) {
                    q.emplace(rn->left);
                }
                if (rn->right) {
                    q.emplace(rn->right);
                }
                if (length == 0) {
                    result.emplace_back(rn->val);
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0199_H
