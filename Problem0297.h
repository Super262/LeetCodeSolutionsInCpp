//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0297_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0297_H

#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string result;
        dfs_ser(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &data) {
        int idx = 0;
        return dfs_des(data, idx);
    }

private:
    void dfs_ser(TreeNode *root, string &result) {
        if (!root) {
            result += "#,";
            return;
        }
        result += to_string(root->val);
        result += ",";
        dfs_ser(root->left, result);
        dfs_ser(root->right, result);
    }

    TreeNode *dfs_des(const string &data, int &idx) {
        if (idx >= data.size()) {
            return NULL;
        }
        if (data[idx] == '#') {
            idx += 2;
            return NULL;
        }
        int k = idx;
        while (data[k] != ',') {
            ++k;
        }
        auto root = new TreeNode(stoi(data.substr(idx, k - idx)));
        idx = k + 1;
        root->left = dfs_des(data, idx);
        root->right = dfs_des(data, idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0297_H
