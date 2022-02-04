//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0126_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0126_H

#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(const string &beginWord,
                                       const string &endWord,
                                       const vector<string> &wordList) {
        unordered_set<string> words_set(wordList.begin(), wordList.end()); // 单词集合
        words_set.insert(beginWord);
        if (!words_set.count(endWord)) {  // 终点未出现
            return {};
        }
        queue<string> q;
        unordered_map<string, int> dist; // 其它单词距起点的距离
        dist[beginWord] = 0;
        q.emplace(beginWord);
        while (!q.empty()) {  // BFS建图
            const auto root = q.front();
            q.pop();
            if (root == endWord) {
                break;
            }
            for (int i = 0; i < (int) root.size(); ++i) {
                auto temp = root;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    temp[i] = ch;
                    if (!words_set.count(temp) || dist.count(temp)) {
                        continue;
                    }
                    dist[temp] = dist[root] + 1;
                    q.emplace(temp);
                }
            }
        }
        if (!dist.count(endWord)) {  // 终点不可达
            return {};
        }
        vector<vector<string>> result;
        vector<string> path;
        path.emplace_back(beginWord);
        dfs(beginWord, endWord, path, result, words_set, dist);
        return result;
    }

private:
    void dfs(const string &st,
             const string &ed,
             vector<string> &path,
             vector<vector<string>> &result,
             unordered_set<string> &words_set,
             unordered_map<string, int> &dist) {
        if (st == ed) {
            result.emplace_back(path);
            return;
        }
        for (int i = 0; i < (int) st.size(); ++i) {
            auto temp = st;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                temp[i] = ch;
                if (!words_set.count(temp) || !dist.count(temp) || dist[temp] != dist[st] + 1) {
                    // 剪枝：下一个点未出现、下一个点的距离不合法
                    continue;
                }
                path.emplace_back(temp);
                dfs(temp, ed, path, result, words_set, dist);
                path.pop_back();
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0126_H
