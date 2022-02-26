//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0765_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0765_H

#include <vector>

using namespace std;

class Solution {
    // 环状图的特点：若交换环内的点，一个环被断开，会多出一个环；若交换不同环的点，两环合并，会少一个环
    // 点是每对情侣(i,i)，边是座位(i,j)，题目要求将原来的x个环转化为n个环，因此，最少操作次数为n-x
    // 由于是无向图，环的数量 == 连通块的数量
    // https://www.acwing.com/solution/content/3957/
public:
    int minSwapsCouples(const vector<int> &row) {
        auto n = (int) row.size();
        auto m = n / 2;
        int parent[m];
        int size[m];
        for (int i = 0; i < m; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < n; i += 2) {
            unionSet(row[i] / 2, row[i + 1] / 2, parent, size);  // 建立并查集
        }
        int cycles = 0;  // 环的数量
        for (int i = 0; i < m; ++i) {
            if (i == findRoot(i, parent)) {  // 发现环
                ++cycles;
            }
        }
        return m - cycles;
    }

private:
    int findRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }

    void unionSet(int a, int b, int parent[], int size[]) {  // 按秩合并
        auto pa = findRoot(a, parent);
        auto pb = findRoot(b, parent);
        if (pa == pb) {
            return;
        }
        if (size[pa] < size[pb]) {
            parent[pa] = pb;
            size[pb] += size[pa];
        } else {
            parent[pb] = pa;
            size[pa] += size[pb];
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0765_H
