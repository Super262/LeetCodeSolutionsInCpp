//
// Created by Fengwei Zhang on 10/17/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0269_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0269_H

#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 拓扑排序：依据升序排列的单词序列建立有向图，边 (a, b) 表示 a < b；输出拓扑序列，表示所有种类字符的升序序列
public:
    string alienOrder(const vector<string> &words) {
        int n = 0;  // 字符种类数
        bool existed[K];  // existed[ch]：字符ch是否存在
        memset(existed, 0, sizeof existed);
        for (const auto &w: words) {
            for (const auto &ch: w) {
                auto i = ch - 'a';
                if (existed[i]) {
                    continue;
                }
                existed[i] = true;
                ++n;
            }
        }
        vector<int> graph[K];  // 有向图
        int in_degree[K];
        memset(in_degree, 0, sizeof in_degree);
        for (int i = 1; i < (int) words.size(); ++i) {
            const auto &s1 = words[i - 1];
            const auto &s2 = words[i];
            if (s1.size() > s2.size() && s1.find(s2) == 0) {  // s1包含s2，且s1比s2长，说明 s1 > s2，非法
                return "";
            }
            int j = 0;
            while (j < (int) min(s1.size(), s2.size())) {  // 找到s1、s2中首个不同字符
                if (s1[j] != s2[j]) {
                    break;
                }
                ++j;
            }
            if (j == (int) min(s1.size(), s2.size())) {  // s2包含s1，且s2不短于s1，说明s1、s2不存在不同的字符
                continue;
            }
            auto a = s1[j] - 'a';
            auto b = s2[j] - 'a';
            graph[a].emplace_back(b);  // 添加边 (a, b)
            ++in_degree[b];
        }
        auto ans = topoSort(graph, n, existed, in_degree);
        if ((int) ans.size() < n) {  // 拓扑序列长度小于n，说明拓扑序不存在
            return "";
        }
        return ans;
    }

private:
    const int K = 26;

    string topoSort(const vector<int> graph[], int n, const bool existed[], int in_degree[]) {
        queue<int> q;
        for (int v = 0; v < K; ++v) {
            if (existed[v] && !in_degree[v]) {
                q.emplace(v);
            }
        }
        string ans;
        ans.reserve(n);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            ans += (char) (u + 'a');
            for (const auto &v: graph[u]) {
                --in_degree[v];
                if (!in_degree[v]) {
                    q.emplace(v);
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0269_H
