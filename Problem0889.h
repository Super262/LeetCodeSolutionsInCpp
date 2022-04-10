//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0889_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0889_H

#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for a binary tree node.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    // 前序 + 后序：答案不唯一，当左子树或右子树不存在时，前序的根结点后面的点既可以是左子树的根，也可以是右子树的根，后序序列同理
    // 题目只要求输出任意解，因此，我们将先序序列的根结点后面的部分看作左子树
    // 难题（AcWing 1259）：中序 + 层序 恢复原树
public:
    TreeNode *constructFromPrePost(const vector<int> &pre, const vector<int> &post) {
        unordered_map<int, int> pos;  // 记录后序节点的索引
        for (int i = 0; i < (int) post.size(); ++i) {
            pos[post[i]] = i;
        }
        return buildTree(pre, 0, (int) pre.size() - 1, post, 0, (int) post.size() - 1, pos);
    }

private:
    TreeNode *buildTree(const vector<int> &pre,
                        int pre_st,
                        int pre_ed,
                        const vector<int> &post,
                        int post_st,
                        int post_ed,
                        unordered_map<int, int> &pos) {
        if (pre_st > pre_ed || post_st > post_ed) {
            return nullptr;
        }
        auto root = new TreeNode(pre[pre_st]);
        if (pre_st == pre_ed && post_st == post_ed) {
            return root;
        }
        auto left_len = pos[pre[pre_st + 1]] - post_st + 1;
        root->left = buildTree(pre, pre_st + 1, pre_st + left_len, post, post_st, post_st + left_len - 1, pos);
        root->right = buildTree(pre, pre_st + left_len + 1, pre_ed, post, post_st + left_len, post_ed - 1, pos);
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0889_H
