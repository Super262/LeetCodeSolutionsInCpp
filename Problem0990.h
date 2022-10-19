//
// Created by Fengwei Zhang on 4/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0990_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0990_H

#include <vector>
#include <string>

using namespace std;

class Problem0990 {
    // 并查集：将等式两端的集合合并，判断不等式两端的集合是否在同个集合
public:
    bool equationsPossible(const vector<string> &equations) {
        const int m = 26;
        int parent[m];
        int set_size[m];
        for (int i = 0; i < m; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        for (const auto &e: equations) {  // 合并等式两端
            if (e[1] == '!') {
                continue;
            }
            auto a = findRoot(e[0] - 'a', parent);
            auto b = findRoot(e[3] - 'a', parent);
            mergeSets(a, b, parent, set_size);
        }
        for (const auto &e: equations) {  // 判断不等式两端
            if (e[1] == '=') {
                continue;
            }
            auto a = findRoot(e[0] - 'a', parent);
            auto b = findRoot(e[3] - 'a', parent);
            if (a == b) {
                return false;
            }
        }
        return true;
    }

private:
    int findRoot(int x, int parent[]) {
        auto u = x;
        while (u != parent[u]) {
            u = parent[u];
        }
        while (x != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    int mergeSets(int a, int b, int parent[], int set_size[]) {
        if (a == b) {
            return -1;
        }
        if (set_size[a] > set_size[b]) {
            parent[b] = a;
            set_size[a] += set_size[b];
            return a;
        }
        parent[a] = b;
        set_size[b] += set_size[a];
        return b;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0990_H
