//
// Created by Fengwei Zhang on 9/6/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1135_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1135_H

#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

class Problam1135
{
private:
    bool prim(int *graph, bool *connected, int n, int *answer)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        bool *selected = (bool *)calloc(n + 1, sizeof(bool));
        bool *reachable = (bool *)calloc(n + 1, sizeof(bool));
        int result = 0;
        int mst_size = 0;

        reachable[1] = true;
        min_heap.emplace(0, 1);
        while (!min_heap.empty())
        {
            pair<int, int> p = min_heap.top();
            min_heap.pop();
            if (selected[p.second])
                continue;

            int v = p.second;
            result += p.first;
            selected[v] = true;
            ++mst_size;

            for (int i = 1; i <= n; ++i)
            {
                if (connected[v * n + i] &&
                    !selected[i])
                {
                    min_heap.emplace(graph[v * n + i], i);
                    if (!reachable[i])
                        reachable[i] = true;
                }
            }
        }

        free(selected);
        free(reachable);

        if (mst_size == n)
        {
            *answer = result;
            return true;
        }
        return false;
    }

public:
    int minimumCost(int n, const vector<vector<int>>& connections)
    {
        int *graph = (int *)malloc((n + 1) * (n + 1) * sizeof(int));
        bool *connected = (bool *)calloc((n + 1) * (n + 1), sizeof(bool));

        for (const vector<int> &e : connections)
        {
            if (connected[e[0] * n + e[1]])
            {
                graph[e[0] * n + e[1]] = min(graph[e[0] * n + e[1]], e[2]);
                graph[e[1] * n + e[0]] = graph[e[0] * n + e[1]];
            }
            else
            {
                connected[e[0] * n + e[1]] = true;
                connected[e[1] * n + e[0]] = true;
                graph[e[0] * n + e[1]] = e[2];
                graph[e[1] * n + e[0]] = e[2];
            }
        }

        int answer;
        if (prim(graph, connected, n, &answer))
        {
            free(graph);
            free(connected);
            return answer;
        }

        free(graph);
        free(connected);
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1135_H
