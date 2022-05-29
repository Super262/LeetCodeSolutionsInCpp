//
// Created by Fengwei Zhang on 5/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0425_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0425_H

#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
    // DFS，Trie优化前缀查询。我们从第1行尝试构建方块，假设当前已经构建到第i行，根据单词方块的定义（参考422题），
    // 第i+1行的单词的前缀应是(square[0][i+1]+square[1][i+1]+...+square[i][i+1])；我们找到所有满足要求的单词，继续DFS
    // 优化：利用Trie加速前缀查询；临时方块只保存被选中的单词的索引，减少递归过程中的字符串拷贝
public:
    vector<vector<string>> wordSquares(const vector<string> &words) {
        auto root = new Node();
        for (int i = 0; i < (int) words.size(); ++i) {
            insertWord(root, words[i], i);
        }
        vector<vector<string>> ans;
        vector<int> temp;  // 临时方块
        const auto n = (int) words[0].size();
        for (int i = 0; i < (int) words.size(); ++i) {
            temp.emplace_back(i);
            dfs(1, n, words, root, temp, ans);
            temp.pop_back();
        }
        return ans;
    }

private:
    struct Node {
        int idx;
        Node *kids[26]{};

        Node() {
            idx = -1;
            for (auto &it: kids) {
                it = nullptr;
            }
        }
    };

    void dfs(int i, int n, const vector<string> &words, Node *root, vector<int> &temp, vector<vector<string>> &ans) {
        if (i == n) {
            vector<string> square;
            square.reserve(temp.size());
            for (const auto &j: temp) {
                square.emplace_back(words[j]);
            }
            ans.emplace_back(square);
            return;
        }
        string prefix;
        prefix.reserve(temp.size());  // 构建新前缀
        for (const auto &j: temp) {
            prefix += words[j][i];
        }
        auto candidates = findWord(root, prefix);
        for (const auto &j: candidates) {
            temp.emplace_back(j);
            dfs(i + 1, n, words, root, temp, ans);
            temp.pop_back();
        }
    }

    void insertWord(Node *root, const string &w, int i) {
        for (const auto &ch: w) {
            auto j = ch - 'a';
            if (!root->kids[j]) {
                root->kids[j] = new Node();
            }
            root = root->kids[j];
        }
        root->idx = i;
    }

    vector<int> findWord(Node *root, const string &prefix) {  // 搜索前缀为prefix的单词
        for (const auto &ch: prefix) {
            auto j = ch - 'a';
            if (!root->kids[j]) {
                return {};
            }
            root = root->kids[j];
        }
        vector<int> ans;
        queue<Node *> q;  // 宽度优先搜索
        if (root->idx != -1) {
            q.emplace(root);
        } else {
            for (const auto &kid: root->kids) {
                if (kid) {
                    q.emplace(kid);
                }
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t->idx != -1) {
                ans.emplace_back(t->idx);
            }
            for (const auto &kid: t->kids) {
                if (kid) {
                    q.emplace(kid);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0425_H
