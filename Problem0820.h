//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0820_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0820_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 查找到所有单词s，满足：words中除去s后，s不包含于任何单词的后缀中
    // 反序插入单词到Trie，记录词频（过滤重复的单词）、是否为叶节点
public:
    int minimumLengthEncoding(const vector<string> &words) {
        auto trie = new Node();
        Node *idx_to_node[words.size()];
        for (int i = 0; i < words.size(); ++i) {
            idx_to_node[i] = insert_reversed(trie, words[i]);
        }
        int ans = 0;
        for (int i = 0; i < (int) words.size(); ++i) {
            if (idx_to_node[i]->has_kid || !idx_to_node[i]->cnt) {
                continue;
            }
            ans += (int) words[i].size() + 1;
            idx_to_node[i]->cnt = 0;  // 避免重复单词：words = {"time","time","time","time"}
        }
        return ans;
    }

private:
    struct Node {
        bool has_kid;
        int cnt;
        Node *kids[26]{};

        Node() {
            has_kid = false;
            cnt = 0;
            for (auto &item: kids) {
                item = nullptr;
            }
        }
    };

    Node *insert_reversed(Node *root, const string &w) {
        for (auto i = (int) w.size() - 1; i >= 0; --i) {
            auto ch = w[i] - 'a';
            if (!root->kids[ch]) {
                root->kids[ch] = new Node();
                root->has_kid = true;
            }
            root = root->kids[ch];
        }
        ++root->cnt;
        return root;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0820_H
