//
// Created by Fengwei Zhang on 5/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0428_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0428_H

#include <string>
#include <algorithm>
#include "nary_node.h"

using namespace std;

class Codec {
    // 序列化时，DFS，以"["、"]"包围子节点全部信息，以","分隔各个节点
    // 反序列化时，DFS，设置全局指针（引用作为参数），遇到"["时调用子过程，解析结束时跳过最后的','
public:
    // Encodes a tree to a single string.
    string serialize(Node *root) {
        if (!root) {
            return "";
        }
        string ans;
        dfs_ser(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    Node *deserialize(const string &s) {
        if (s.empty()) {
            return nullptr;
        }
        int idx = 0;
        return dfs_des(s, idx);
    }

private:
    void dfs_ser(Node *root, string &ans) {
        ans += to_string(root->val);
        ans += ',';
        if (root->children.empty()) {
            return;
        }
        ans += '[';
        for (const auto &kid: root->children) {
            dfs_ser(kid, ans);
        }
        ans += ']';
        ans += ',';
    }

    Node *dfs_des(const string &s, int &idx) {
        auto j = idx;
        while (j < (int) s.size() && s[j] != ',') {
            ++j;
        }
        auto root = new Node(stoi(s.substr(idx, j - idx)));
        idx = j + 1;  // 跳过","
        if (idx >= (int) s.size() || s[idx] != '[') {
            return root;
        }
        ++idx;  // 跳过"["
        while (s[idx] != ']') {
            root->children.emplace_back(dfs_des(s, idx));
        }
        idx += 2;  // 跳过"]"和","
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0428_H
