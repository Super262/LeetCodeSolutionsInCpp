//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0677_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0677_H

#include <string>
#include <queue>

using namespace std;

class MapSum {
    // 涉及前缀搜索，使用Trie保存每个前缀对应的值
    // insert：插入单词到Trie；sum：找到prefix的后继p，从p开始BFS，累加所有value
public:
    MapSum() {
        root = new Node();
    }

    void insert(const string &key, const int val) {
        auto p = root;
        for (const auto &ch: key) {
            if (!p->kids[ch - 'a']) {
                p->kids[ch - 'a'] = new Node();
            }
            p = p->kids[ch - 'a'];
        }
        p->value = val;
    }

    int sum(const string &prefix) {
        auto p = root;
        for (const auto &ch: prefix) {
            if (!p->kids[ch - 'a']) {
                return 0;
            }
            p = p->kids[ch - 'a'];
        }
        int res = 0;
        queue<Node *> q;
        q.emplace(p);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            res += t->value;
            for (const auto nxt: t->kids) {
                if (!nxt) {
                    continue;
                }
                q.emplace(nxt);
            }
        }
        return res;
    }

private:
    struct Node {
        int value;
        Node *kids[26]{};

        Node() {
            value = 0;
            for (auto &item: kids) {
                item = nullptr;
            }
        }
    };

    Node *root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0677_H
