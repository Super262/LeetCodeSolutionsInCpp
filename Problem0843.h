//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0843_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0843_H

#include <cstring>
#include <vector>
#include <string>

using namespace std;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 */
class Master {
public:
    int guess(string word);
};

class Solution {
    // 极小化最坏情况
public:
    void findSecretWord(const vector<string> &words, Master &master) {
        const auto n = (int) words.size();
        const auto matched_len = countMatched(words);
        bool visited[n];
        memset(visited, 0, sizeof visited);
        for (int k = 0; k < K; ++k) {
            int i = -1;
            int w = n;
            for (int j = 0; j < n; ++j) {
                if (visited[j]) {
                    continue;
                }
                int t = 0;
                for (int u = 0; u <= M; ++u) {
                    t = max(t, countTarget(j, n, u, visited, matched_len));
                }
                if (w > t) {  // 保存最坏情况
                    i = j;
                    w = t;
                }
            }
            auto res = master.guess(words[i]);
            if (res == M) {
                return;
            }
            visited[i] = true;
            for (int j = 0; j < n; ++j) {
                if (matched_len[i][j] == res) {
                    continue;
                }
                visited[j] = true;
            }
        }
    }

private:
    vector<vector<int>> countMatched(const vector<string> &words) {
        const auto n = (int) words.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < M; ++k) {
                    if (words[i][k] != words[j][k]) {
                        continue;
                    }
                    ++cnt;
                }
                ans[i][j] = cnt;
            }
        }
        return ans;
    }

    int countTarget(int idx, int n, int t, const bool selected[], const vector<vector<int>> &matched_len) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && matched_len[idx][j] == t) {
                ++ans;
            }
        }
        return ans;
    }

    const int M = 6, K = 10;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0843_H
