//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0765_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0765_H

#include <vector>

using namespace std;

class Problem0765 {
    // 通过观察，我们发现：如果有2对情侣互相坐错了位置，我们至多只需要交换1次；如果有3对情侣互相坐错了位置，"A1, B2, B1, C2, C1, A2"，
    // 他们之间形成了1个环，我们只需要交换2次；如果有4对情侣互相坐错了位置，"A1, B2, B1, C2, C1, D2, D1, A2"，我们需要交换3次
    // 以此类推，若k对情侣形成一个环状的错误链，我们只需要交换k-1次就可以将这k对情侣的位置排好；因此，问题转化成n对情侣中，有几个错误环
    // 我们可以使用并查集来处理：每次遍历相邻的2个位置，若他们是情侣，他们处于大小为1的错误环，只需要交换0次；若他们不是情侣，我们将他们合并，
    // 将所有的错坐情侣合并和后，答案就是情侣对数减环个数；https://www.acwing.com/solution/content/3957/
public:
    int minSwapsCouples(const vector<int> &row) {
        const auto n = (int) row.size();
        const auto m = n / 2;
        int parent[m];
        int set_size[m];
        for (int i = 0; i < m; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        for (int i = 0; i < n; i += 2) {
            auto pa = findRoot(row[i] / 2, parent);
            auto pb = findRoot(row[i + 1] / 2, parent);
            if (pa == pb) {
                continue;
            }
            mergeSets(pa, pb, parent, set_size);  // 合并2个不同环
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
        auto u = x;
        while (parent[u] != u) {
            u = parent[u];
        }
        while (x != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    int mergeSets(int pa, int pb, int parent[], int set_size[]) {  // 按秩合并
        if (pa == pb) {
            return -1;
        }
        if (set_size[pa] < set_size[pb]) {
            parent[pa] = pb;
            set_size[pb] += set_size[pa];
            return pb;
        }
        parent[pb] = pa;
        set_size[pa] += set_size[pb];
        return pa;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0765_H
