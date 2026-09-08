//
// Created by Fengwei Zhang on 9/8/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2493_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2493_H

#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

class Problem2493
{
public:
    int magnificentSets(int n, const vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n + 1);
        int *color = (int *)calloc(n + 1, sizeof(int));
        vector<vector<int>> components;

        for (const vector<int> &e : edges)
        {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }

        /*
        ** 一次遍历同时：
        **
        ** 1. 判断 bipartite
        ** 2. 找 connected component
        ** 3. 保存 component 的节点
        */
        for (int x = 1; x <= n; ++x)
        {
            if (color[x])
                continue;

            components.emplace_back();

            if (!colorComponent(x,
                                (int)components.size() - 1,
                                graph,
                                color,
                                components.back()))
            {
                free(color);
                return -1;
            }
        }

        /*
        ** visited 使用 timestamp，
        ** 所以不需要每轮 BFS memset。
        */
        int *visited = (int *)calloc(n + 1, sizeof(int));
        int stamp = 0;
        int answer = 0;

        for (const vector<int> &nodes : components)
        {
            int best = 0;

            for (int st : nodes)
            {
                ++stamp;
                best = max(best, bfsLevel(st, graph, visited, stamp));
            }

            answer += best;
        }

        free(color);
        free(visited);
        return answer;
    }

private:
    bool colorComponent(int st,
                        int comp_idx,
                        const vector<vector<int>> &graph,
                        int *color,
                        vector<int> &nodes)
    {
        queue<int> q;

        q.emplace(st);
        color[st] = 1;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            nodes.emplace_back(x);

            for (int y : graph[x])
            {
                if (!color[y])
                {
                    color[y] = 3 - color[x];
                    q.emplace(y);
                }
                else if (color[y] == color[x])
                    return false;
            }
        }

        return true;
    }

    int bfsLevel(int st,
                 const vector<vector<int>> &graph,
                 int *visited,
                 int stamp)
    {
        queue<int> q;
        int answer = 0;

        q.emplace(st);
        visited[st] = stamp;

        while (!q.empty())
        {
            ++answer;
            for (int i = (int)q.size(), x; i; --i)
            {
                x = q.front();
                q.pop();

                for (int y : graph[x])
                {
                    if (visited[y] == stamp)
                        continue;

                    visited[y] = stamp;
                    q.emplace(y);
                }
            }
        }

        return answer;
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM2493_H
