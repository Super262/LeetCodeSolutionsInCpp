//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0449_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0449_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    // 本题测试用例不包含重复元素
    // 利用BST性质，只需前序序列就可以还原：左子树段小于根结点，右子树段大于根结点
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        preOrder(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &s) {
        vector<int> data;
        stringstream ssin(s);
        int x;
        while (ssin >> x) {
            data.emplace_back(x);
        }
        int u = 0;
        return dfs(data, u, INT_MAX, INT_MIN);
    }

private:
    void preOrder(TreeNode *root, string &res) {
        if (!root) {
            return;
        }
        res += to_string(root->val) + " ";
        preOrder(root->left, res);
        preOrder(root->right, res);
    }

    TreeNode *dfs(const vector<int> &data, int &u, int maxv, int minv) {
        if (u >= data.size() || data[u] < minv || data[u] > maxv) {
            return NULL;
        }
        auto root = new TreeNode(data[u]);
        ++u;
        root->left = dfs(data, u, root->val, minv);
        root->right = dfs(data, u, maxv, root->val);
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
