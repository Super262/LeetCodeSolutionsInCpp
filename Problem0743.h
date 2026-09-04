//
// Created by Fengwei Zhang on 2/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0743_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0743_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0743
{
public:
    int networkDelayTime(const vector<vector<int>>& times, int n, int k)
    {
        /* Dijkstra */
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        bool *selected = (bool *)malloc((n + 1) * sizeof(bool));
        int *dist = (int *)malloc((n + 1) * sizeof(int));
        vector<vector<pair<int, int>>> graph(n + 1);

        for (const vector<int> &edge : times)
            graph[edge[0]].emplace_back(edge[2], edge[1]);

        for (int i = 1; i <= n; ++i)
        {
            selected[i] = false;
            if (i == k)
                dist[k] = 0;
            else
                dist[i] = -1;
        }

        min_heap.emplace(0, k);
        while (!min_heap.empty())
        {
            pair<int, int> p = min_heap.top();
            min_heap.pop();

            if (selected[p.second])
                continue;
            selected[p.second] = true;

            for (const pair<int, int> &np : graph[p.second])
            {
                if (dist[np.second] == -1)
                    dist[np.second] = dist[p.second] + np.first;
                else
                    dist[np.second] = min(dist[np.second], dist[p.second] + np.first);
                min_heap.emplace(dist[np.second], np.second);
            }
        }

        int answer = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (selected[i])
                answer = max(answer, dist[i]);
            else
            {
                free(selected);
                free(dist);
                return -1;
            }
        }

        free(selected);
        free(dist);
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0743_H
