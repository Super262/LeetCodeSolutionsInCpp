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
    struct Edge
    {
        int x, y, w;

        bool operator<(const Edge &e) const
        {
            return w < e.w;
        }
    };

    int findRoot(int x, int *parent)
    {
        int u = x;
        int t;

        while (parent[u] != u)
            u = parent[u];

        while (x != u)
        {
            t = parent[x];
            parent[x] = u;
            x = t;
        }

        return u;
    }

    int mergeSets(int a, int b, int *parent, int *set_size)
    {
        int pa = findRoot(a, parent);
        int pb = findRoot(b, parent);

        if (pa == pb)
            return pa;

        if (set_size[pa] > set_size[pb])
        {
            parent[pb] = pa;
            set_size[pa] += set_size[pb];
            return pa;
        }

        parent[pa] = pb;
        set_size[pb] += set_size[pa];
        return pb;
    }

    int kruskal(struct Edge *edges, int m, int *parent, int *set_size, int *answer)
    {
        int result = 0;
        int edges_cnt = 0;

        sort(edges, edges + m);
        for (int i = 0, x, y, w; i < m; ++i)
        {
            x = edges[i].x;
            y = edges[i].y;

            if (findRoot(x, parent) == findRoot(y, parent))
                continue;
            
            mergeSets(x, y, parent, set_size);
            result += edges[i].w;
            ++edges_cnt;
        }

        *answer = result;
        return edges_cnt;
    }

public:
    int minimumCost(int n, const vector<vector<int>>& connections)
    {
        int m = (int)connections.size();
        struct Edge *edges = (struct Edge *)malloc(sizeof(struct Edge) * m);
        int *parent = (int *)malloc(sizeof(int) * (n + 1));
        int *set_size = (int *)malloc(sizeof(int) * (n + 1));
        int answer;

        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            set_size[i] = 1;
        }

        for (int i = 0; i < m; ++i)
        {
            edges[i].x = connections[i][0];
            edges[i].y = connections[i][1];
            edges[i].w = connections[i][2];
        }

        if (kruskal(edges, m, parent, set_size, &answer) == n - 1)
        {
            free(edges);
            free(parent);
            free(set_size);
            return answer;
        }

        free(edges);
        free(parent);
        free(set_size);
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1135_H
