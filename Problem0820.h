//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0820_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0820_H

#include <vector>
#include <string>

using namespace std;

class Problem0820 {
    // Trie结构；对于words中任意2个单词x、y，若x是y的后缀，x不会出现在编码字符串s中
    // 因此，我们可以使用Trie结构快速验证后缀：插入每个单词word的逆序，判断子节点是否存在
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
