//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0332_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0332_H

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    // 求解字典需最小的欧拉路径
    // 有向图欧拉路径存在条件：
    //      起点：出度 = 入度 + 1；
    //      终点：入度 = 出度 + 1；
    //      其余点：入度 == 出度
    // 求解欧拉路径：从起点开始DFS：https://www.acwing.com/solution/content/359/；回溯后反序
public:
    vector<string> findItinerary(const vector<vector<string>> &tickets) {
        vector<string> answer;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (const auto &t: tickets) {
            graph[t[0]].emplace(t[1]);
        }
        string st = "JFK";
        dfs(st, graph, answer);
        reverse(answer.begin(), answer.end());
        return answer;
    }

private:
    void dfs(const string &st,
             unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &graph,
             vector<string> &answer) {
        while (!graph[st].empty()) {
            auto nextSt = graph[st].top();
            graph[st].pop();
            dfs(nextSt, graph, answer);
        }
        answer.emplace_back(st);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0332_H
