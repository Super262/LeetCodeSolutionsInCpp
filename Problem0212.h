//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0212_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0212_H

#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        auto root = new Node();
        for (int i = 0; i < (int) words.size(); ++i) {
            insertWord(root, words[i], i);
        }
        unordered_set<int> ids;  // 使用set，同时记录并判重
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int u = board[i][j] - 'a';
                if (!root->kids[u]) {
                    continue;
                }
                dfs(board, i, j, root->kids[u], ids);
            }
        }
        vector<string> result;
        result.reserve(ids.size());
        for (auto i: ids) {
            result.emplace_back(words[i]);
        }
        return result;
    }

private:
    struct Node {
        int idx;
        Node *kids[26]{};

        Node() {
            idx = -1;
            for (auto &kid: kids) {  // 不能用memset初始化指针数组
                kid = nullptr;
            }
        }
    };

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

    void insertWord(Node *root, const string &word, const int idx) {
        auto p = root;
        for (auto ch: word) {
            int u = ch - 'a';
            if (!p->kids[u]) {
                p->kids[u] = new Node();
            }
            p = p->kids[u];
        }
        p->idx = idx;
    }

    void dfs(vector<vector<char>> &board, const int x, const int y, const Node *root, unordered_set<int> &ids) {
        if (root->idx != -1) {
            ids.insert(root->idx);  // 这里后面没有return（例如，结果中的两个单词可能是oa和oaa）
        }
        const auto ch = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; ++i) {
            auto nx = x + dx[i];
            auto ny = y + dy[i];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == '.') {
                continue;
            }
            int u = board[nx][ny] - 'a';
            if (!root->kids[u]) {
                continue;
            }
            dfs(board, nx, ny, root->kids[u], ids);
        }
        board[x][y] = ch;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0212_H
