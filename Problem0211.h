//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0211_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0211_H

#include <string>

using namespace std;

class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(const string &word) {
        auto current = root;
        for (const auto ch: word) {
            auto idx = ch - 'a';
            if (!current->children[idx]) {
                current->children[idx] = new Node();
            }
            current = current->children[idx];
        }
        current->isWord = true;
    }

    bool search(const string &word) {
        return dfs(root, word, 0);
    }

private:
    struct Node {
        bool isWord;
        Node *children[26];

        Node() {
            isWord = false;
            for (auto &item: children) {
                item = nullptr;
            }
        }
    };

    Node *root;

    bool dfs(Node *start, const string &word, const int &idx) {
        if (!start) {
            return false;
        }
        if (idx == word.size()) {
            return start->isWord;
        }
        if (word[idx] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (dfs(start->children[i], word, idx + 1)) {
                    return true;
                }
            }
            return false;
        }
        return dfs(start->children[word[idx] - 'a'], word, idx + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0211_H
