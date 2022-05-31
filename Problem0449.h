//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0449_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0449_H

#include <string>
#include <vector>
#include <sstream>
#include "treenode.h"

using namespace std;

class Codec {
    // 本题测试用例不包含重复元素；利用BST性质，只需前序序列就可以还原：左子树段小于根结点，右子树段大于根结点
    // 细节：反序列化时，由于我们没有单独为空节点设置标记，因此我们无法渐进式读取s，只能预解析s所有内容
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) {
            return "";
        }
        string s;
        dfs_ser(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &s) {
        if (s.empty()) {
            return nullptr;
        }
        vector<int> data;
        stringstream ssin(s);
        int x;
        while (ssin >> x) {
            data.emplace_back(x);
        }
        int u = 0;
        return dfs_des(data, u, INT_MAX, INT_MIN);
    }

private:
    void dfs_ser(TreeNode *root, string &s) {
        if (!root) {
            return;
        }
        s += to_string(root->val) + " ";
        if (root->left) {
            dfs_ser(root->left, s);
        }
        if (root->right) {
            dfs_ser(root->right, s);
        }
    }

    TreeNode *dfs_des(const vector<int> &data, int &u, int maxv, int minv) {
        auto root = new TreeNode(data[u]);
        ++u;
        if (u < data.size() && data[u] < root->val && data[u] > minv) {
            root->left = dfs_des(data, u, root->val, minv);
        }
        if (u < data.size() && data[u] < maxv && data[u] > root->val) {
            root->right = dfs_des(data, u, maxv, root->val);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0449_H
