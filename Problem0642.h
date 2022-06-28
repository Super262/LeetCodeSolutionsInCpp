//
// Created by Fengwei Zhang on 6/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0642_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0642_H

#include <vector>
#include <string>
#include <queue>

using namespace std;

class AutocompleteSystem {
    // 建立Trie，节点Node存储times和key；key存储句子，times记录key的频率
    // 设当前的查询关键字为current，输入字符为c；若c为'#'，我们将current加入Trie（current对应的叶节点的频率加1）
    // 若c为普通字符（包括' '），更新current为current+c，在Trie查找所有前缀为current的叶节点（BFS或DFS），再根据题意排序并返回
public:
    AutocompleteSystem(const vector<string> &sentences, const vector<int> &times) {
        root = new Node();
        for (int i = 0; i < (int) sentences.size(); ++i) {
            insertWord(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            insertWord(current, 1);
            current = "";
            return {};
        }
        current += c;
        auto p = root;
        for (const auto &ch: current) {
            auto idx = ch - 'a';
            if (ch == ' ') {
                idx = 26;
            }
            if (!p->kids[idx]) {
                return {};
            }
            p = p->kids[idx];
        }
        vector<pair<int, string>> temp;
        queue<Node *> q;
        q.emplace(p);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t->times > 0) {
                temp.emplace_back(t->times, t->key);
            }
            for (const auto &it: t->kids) {
                if (it) {
                    q.emplace(it);
                }
            }
        }
        sort(temp.begin(), temp.end(), [&](const pair<int, string> &a, pair<int, string> &b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        vector<string> ans;
        for (int i = 0; i < min(3, (int) temp.size()); ++i) {
            ans.emplace_back(temp[i].second);
        }
        return ans;
    }

private:
    struct Node {
        int times;
        string key;
        Node *kids[27]{};

        Node() {
            times = 0;
            for (auto &item: kids) {
                item = nullptr;
            }
        }
    };

    Node *root;
    string current;

    void insertWord(const string &s, int times) {
        auto p = root;
        for (const auto &ch: s) {
            auto idx = ch - 'a';
            if (ch == ' ') {
                idx = 26;
            }
            if (!p->kids[idx]) {
                p->kids[idx] = new Node();
            }
            p = p->kids[idx];
        }
        p->times += times;
        p->key = s;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0642_H
