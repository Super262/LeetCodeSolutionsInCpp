//
// Created by Fengwei Zhang on 11/13/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0208_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0208_H

#include <string>
#include <cstring>

using namespace std;

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
            if (!current->kids[idx]) {
                current->kids[idx] = new Node();
            }
            current = current->kids[idx];
        }
        current->is_word = true;
    }

    bool search(const string &word) {
        auto current = root;
        for (const auto &ch: word) {
            auto idx = ch - 'a';
            if (!current->kids[idx]) {
                return false;
            }
            current = current->kids[idx];
        }
        return current->is_word;
    }

    bool startsWith(const string &prefix) {
        auto current = root;
        for (const auto &ch: prefix) {
            auto idx = ch - 'a';
            if (!current->kids[idx]) {
                return false;
            }
            current = current->kids[idx];
        }
        return true;
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

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0208_H
