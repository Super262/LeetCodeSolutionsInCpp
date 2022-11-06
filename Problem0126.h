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

class Problem0126 {
    // BFS：根据各个单词间的关系，建立有向图（只保存dist，不保存边a->b）
    // DFS：搜索从st到ed的所有路径，注意剪枝
public:
    vector<vector<string>> findLadders(const string &begin_word,
                                       const string &end_word,
                                       const vector<string> &word_list) {
        unordered_set<string> words_set(word_list.begin(), word_list.end()); // 单词集合
        words_set.insert(begin_word);
        if (!words_set.count(end_word)) {  // 终点未出现
            return {};
        }
        queue<string> q;
        unordered_map<string, int> dist; // 其它单词距起点的距离
        dist[begin_word] = 0;
        q.emplace(begin_word);
        while (!q.empty()) {  // BFS建图
            auto root = q.front();
            if (root == end_word) {
                break;
            }
            q.pop();
            auto rd = dist[root];
            for (int i = 0; i < (int) root.size(); ++i) {
                auto t = root[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    root[i] = ch;
                    if (!words_set.count(root) || dist.count(root)) {
                        continue;
                    }
                    dist[root] = rd + 1;
                    q.emplace(root);
                }
                root[i] = t;
            }
        }
        if (!dist.count(end_word)) {  // 终点不可达
            return {};
        }
        vector<vector<string>> result;
        vector<string> path;
        path.emplace_back(begin_word);
        dfs(begin_word, end_word, path, result, words_set, dist);
        return result;
    }

private:
    void dfs(const string &st,
             const string &ed,
             vector<string> &path,
             vector<vector<string>> &res,
             const unordered_set<string> &words_set,
             const unordered_map<string, int> &dist) {
        if (st == ed) {
            res.emplace_back(path);
            return;
        }
        auto temp = st;
        auto rd = dist.find(st)->second;
        for (int i = 0; i < (int) temp.size(); ++i) {
            auto t = temp[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                temp[i] = ch;
                // 剪枝：下一个点未出现、下一个点的距离不合法
                if (!words_set.count(st) || !dist.count(temp) || dist.find(temp)->second != rd + 1) {
                    continue;
                }
                path.emplace_back(temp);
                dfs(temp, ed, path, res, words_set, dist);
                path.pop_back();
            }
            temp[i] = t;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0126_H
