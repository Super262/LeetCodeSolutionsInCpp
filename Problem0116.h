//
// Created by Fengwei Zhang on 11/6/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0116_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0116_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Problem0116 {
public:
    Node *connect(Node *root) { // 注意：输入是满二叉树
        if (!root) {
            return root;
        }
        auto current = root;
        while (current->left) { // 下一层存在
            for (auto p = current; p; p = p->next) { // 处理下一层
                p->left->next = p->right;
                if (p->next) {
                    p->right->next = p->next->left;
                }
            }
            current = current->left;
        }
        return root;
    }
}

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0116_H
