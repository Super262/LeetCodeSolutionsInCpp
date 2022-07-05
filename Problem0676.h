//
// Created by Fengwei Zhang on 2/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0676_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0676_H

#include <vector>
#include <queue>
#include <string>

using namespace std;

class MagicDictionary {
    // buildDict：根据输入建立Trie；C++技巧：使用内置的tuple记录多个状态
    // search：从Trie的根结点、word的第0号字符开始BFS，并记录当前查找路径上是否存在修改操作；若可以搜索到尾部、经历最多1次修改，返回true
public:
    MagicDictionary() {
        root = new Node();
    }

    void buildDict(const vector<string> &dict) {
        for (const auto &s: dict) {
            auto p = root;
            for (const auto &ch: s) {
                if (!p->kids[ch - 'a']) {
                    p->kids[ch - 'a'] = new Node();
                }
                p = p->kids[ch - 'a'];
            }
            p->is_word = true;
        }
    }

    bool search(const string &word) {  // BFS，每个元组保存3个信息（下标，修改状态，结点指针）
        queue<tuple<int, bool, Node *>> q;
        q.push(make_tuple(0, false, root));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto idx = get<0>(t);
            auto modified = get<1>(t);
            auto cur = get<2>(t);
            if (idx == (int) word.size()) {
                if (cur->is_word && modified) {
                    return true;
                }
                continue;
            }
            auto ch = word[idx] - 'a';
            if (!modified) {
                for (int i = 0; i < 26; ++i) {
                    if (i == ch || !cur->kids[i]) {
                        continue;
                    }
                    q.push(make_tuple(idx + 1, true, cur->kids[i]));
                }
            }
            if (cur->kids[ch]) {
                q.push(make_tuple(idx + 1, modified, cur->kids[ch]));
            }
        }
        return false;
    }

private:
    struct Node {
        bool is_word;
        Node *kids[26]{};

        Node() {
            is_word = false;
            for (auto &item: kids) {
                item = nullptr;
            }
        }
    };

    Node *root;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
#endif //LEETCODESOLUTIONSINCPP_PROBLEM0676_H
