//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0745_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0745_H

#include <string>
#include <vector>

using namespace std;

class WordFilter {
    // 直接背诵思路：https://www.acwing.com/solution/content/3916/
    // 朴素想法就是分别建立前缀树和后缀树，然后用DFS求解前缀集合和后缀集合，求两个集合的交集
    // 我们对每个单词的所有后缀（包括空串）以及自己，拼接上"#"，再拼接上原单词，把整个字符串插入到Trie中
    // 例如，对于单词"apple"，我们插入"#apple", "e#apple", "le#apple", "ple#apple", "pple#apple", "apple#apple"
    // 根据题目要求，我们从前向后插入单词序列，确保公共前缀节点保存的是最大的索引
public:
    WordFilter(const vector<string> &words) {
        root = new Node();
        const auto n = (int) words.size();
        for (auto i = 0; i < n; ++i) {  // 题目要求结果的索引尽可能大，所以从前向后插入单词
            auto cur = "#" + words[i];
            insert(cur, i);
            for (auto j = (int) words[i].size() - 1; j >= 0; --j) {
                cur.insert(cur.begin(), words[i][j]);
                insert(cur, i);
            }
        }
    }

    int f(const string &prefix, const string &suffix) {
        auto w = suffix + "#" + prefix;
        return query(w);
    }

private:
    static const int M = 26;

    struct Node {
        int idx;
        Node *kids[M + 1]{};

        Node() {
            idx = -1;
            for (auto &item: kids) {
                item = nullptr;
            }
        }
    };

    Node *root;

    void insert(const string &w, const int idx) {
        auto p = root;
        for (const auto &ch: w) {
            int u;
            if (ch == '#') {
                u = M;
            } else {
                u = ch - 'a';
            }
            if (!p->kids[u]) {
                p->kids[u] = new Node();
            }
            p = p->kids[u];
            p->idx = idx;
        }
    }

    int query(const string &w) {
        auto p = root;
        for (const auto &ch: w) {
            int u;
            if (ch == '#') {
                u = M;
            } else {
                u = ch - 'a';
            }
            if (!p->kids[u]) {
                return -1;
            }
            p = p->kids[u];
        }
        return p->idx;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0745_H
