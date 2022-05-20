//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0297_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0297_H

#include <string>
#include "treenode.h"

using namespace std;

class Codec {
    // 编码、解码都采用类似先序遍历的思路
    // 编码：","分隔节点值，"#"指示空节点；解码：若当前为空节点（"#"），指针后移2位（跳过当前节点和分隔符）
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string result;
        dfs_encode(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &data) {
        int idx = 0;
        return dfs_decode(data, idx);
    }

private:
    void dfs_encode(TreeNode *root, string &result) {
        if (!root) {
            result += "#,";
            return;
        }
        result += to_string(root->val);
        result += ",";
        dfs_encode(root->left, result);
        dfs_encode(root->right, result);
    }

    TreeNode *dfs_decode(const string &data, int &idx) {
        if (idx >= (int) data.size()) {
            return nullptr;
        }
        if (data[idx] == '#') {
            idx += 2;  // 跳过当前节点和分隔符
            return nullptr;
        }
        auto k = idx;
        while (data[k] != ',') {
            ++k;
        }
        auto root = new TreeNode(stoi(data.substr(idx, k - idx)));
        idx = k + 1;  // 跳过分隔符
        root->left = dfs_decode(data, idx);
        root->right = dfs_decode(data, idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0297_H
