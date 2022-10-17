//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1032_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1032_H

#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

class StreamChecker {
    // AC自动机（Aho–Corasick Algorithm）模版题
public:
    StreamChecker(vector<string> &words) {
        root = new Node();
        now = root;
        for (const auto &s: words) {
            insertWord(s);
        }
        buildAC();
    }

    bool query(char letter) {
        now = now->kids[letter - 'a'];
        return now->is_end;
    }

private:
    static const int K = 26;

    struct Node {
        bool is_end;
        Node *kids[K]{};
        Node *fail;

        Node() {
            is_end = false;
            for (auto &item: kids) {
                item = nullptr;
            }
            fail = nullptr;
        }
    };

    Node *root;  // 根指针
    Node *now;  // 查询指针

    void insertWord(const string &w) {
        auto cur = root;
        for (const auto &ch: w) {
            auto i = ch - 'a';
            if (!cur->kids[i]) {
                cur->kids[i] = new Node();
            }
            cur = cur->kids[i];
        }
        cur->is_end = true;
    }

    void buildAC() {
        queue<Node *> q;
        root->fail = root;
        for (auto &kid: root->kids) {
            if (kid) {
                kid->fail = root;
                q.emplace(kid);
            } else {
                kid = root;
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            u->is_end = u->is_end || u->fail->is_end;
            for (int i = 0; i < K; ++i) {
                if (u->kids[i]) {
                    u->kids[i]->fail = u->fail->kids[i];
                    q.emplace(u->kids[i]);
                } else {
                    u->kids[i] = u->fail->kids[i];
                }
            }
        }
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1032_H
