//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0208_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0208_H

class Trie {
    // 背诵代码！
    // Trie特点：边保存字符，节点保存前缀信息
public:
    Trie() {
        root = new Node();
    }

    void insert(const string &word) {
        auto current = root;
        for (const auto &ch: word) {
            auto idx = ch - 'a';
            if (!current->children[idx]) {
                current->children[idx] = new Node();
            }
            current = current->children[idx];
        }
        current->isWord = true;
    }

    bool search(const string &word) {
        auto current = root;
        for (const auto &ch: word) {
            auto idx = ch - 'a';
            if (!current->children[idx]) {
                return false;
            }
            current = current->children[idx];
        }
        return current->isWord;
    }

    bool startsWith(const string &prefix) {
        auto current = root;
        for (const auto &ch: prefix) {
            auto idx = ch - 'a';
            if (!current->children[idx]) {
                return false;
            }
            current = current->children[idx];
        }
        return true;
    }

private:
    struct Node {
        bool isWord;
        Node *children[26];

        Node() {
            isWord = false;
            for (auto & item : children) {
                item = nullptr;
            }
        }
    };

    Node *root;

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0208_H
