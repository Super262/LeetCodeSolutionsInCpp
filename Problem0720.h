//
// Created by Fengwei Zhang on 2/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0720_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0720_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // Trie + 前序遍历
    // Trie保存单词的索引；前序搜索保证结果的子典序最最小
public:
    string longestWord(const vector<string> &words) {
        auto root = new Node();
        for (int i = 0; i < words.size(); ++i) {
            insert(root, words[i], i);
        }
        auto res = preOrder(root, 0);
        if (res.second == -1) {
            return "";
        }
        return words[res.second];
    }

private:
    struct Node {
        int idx;
        Node *items[26]{};

        Node() {
            idx = -1;
            for (auto &x: items) {
                x = nullptr;
            }
        }
    };

    void insert(Node *root, const string &w, const int idx) {
        for (const auto &ch: w) {
            auto i = ch - 'a';
            if (!root->items[i]) {
                root->items[i] = new Node();
            }
            root = root->items[i];
        }
        root->idx = idx;
    }

    pair<int, int> preOrder(Node *root, int l) {
        pair<int, int> res(l, root->idx);
        for (const auto kid: root->items) {
            if (!kid || kid->idx == -1) {  // 不要忘记排除idx == -1的结点
                continue;
            }
            auto t = preOrder(kid, l + 1);
            if (t.first > res.first) {
                res.first = t.first;
                res.second = t.second;
            }
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0720_H
