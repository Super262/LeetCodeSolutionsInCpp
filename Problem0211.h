//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0211_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0211_H

#include <string>
#include <cstring>

using namespace std;

class WordDictionary {
    // 经典算法，必须掌握：在Trie上执行DFS
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(const string &word) {
        auto current = root;
        for (const auto ch: word) {
            auto idx = ch - 'a';
            if (!current->kids[idx]) {
                current->kids[idx] = new Node();
            }
            current = current->kids[idx];
        }
        current->is_word = true;
    }

    bool search(const string &word) {
        return dfs(root, word, 0);
    }

private:
    struct Node {
        bool is_word;
        Node *kids[26]{};

        Node() {
            is_word = false;
            for (auto &kid: kids) {
                kid = nullptr;
            }
        }
    };

    Node *root;

    bool dfs(Node *root, const string &word, const int idx) {
        if (idx == (int) word.size()) {
            return root->is_word;
        }
        if (word[idx] == '.') {
            for (const auto &kid: root->kids) {
                if (!kid) {
                    continue;
                }
                if (dfs(kid, word, idx + 1)) {
                    return true;
                }
            }
            return false;
        }
        if (!root->kids[word[idx] - 'a']) {
            return false;
        }
        return dfs(root->kids[word[idx] - 'a'], word, idx + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0211_H
