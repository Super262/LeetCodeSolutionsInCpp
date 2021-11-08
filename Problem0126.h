//
// Created by Fengwei Zhang on 11/7/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0126_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0126_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Problem0126 {
public:
    vector<vector<string>> findLadders(const string &beginWord,
                                       const string &endWord,
                                       const vector<string> &wordList) {
        unordered_set<string> wordsSet; // 单词集合
        unordered_map<string, int> dist; // 其它单词距起点的距离
        queue <string> q;
        for (const auto &s: wordList) {
            wordsSet.insert(s);
        }
        wordsSet.insert(beginWord);
        vector<vector<string>> result;
        if (!wordsSet.count(endWord)) {  // 终点未出现
            return result;
        }
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
                    if (!wordsSet.count(temp) || dist.count(temp)) {
                        continue;
                    }
                    dist[temp] = dist[root] + 1;
                    q.emplace(temp);
                }
            }
        }
        if (!dist.count(endWord)) {  // 终点不可达
            return result;
        }
        vector<string> path;
        path.emplace_back(beginWord);
        dfs(beginWord, endWord, path, result, wordsSet, dist);
        return result;
    }

    void dfs(const string &st,
             const string &ed,
             vector<string> &path,
             vector<vector<string>> &result,
             unordered_set<string> &wordsSet,
             unordered_map<string, int> &dist) {
        if (st == ed) {
            result.emplace_back(path);
            return;
        }
        for (int i = 0; i < (int) st.size(); ++i) {
            auto temp = st;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                temp[i] = ch;
                if (!wordsSet.count(temp) || !dist.count(temp) || dist[temp] != dist[st] + 1) {
                    // 剪枝：下一个点未出现、下一个点的距离不合法
                    continue;
                }
                path.emplace_back(temp);
                dfs(temp, ed, path, result, wordsSet, dist);
                path.pop_back();
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0126_H
