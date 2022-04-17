//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0952_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0952_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 若a、b存在最大公约数，我们将两数合并；由于输入的数据量很大，我们不能直接枚举2个数（O(n^2)）、然后用GCD判断最大公约数
    // 为优化速度，我们可以记录以因子a为约数的数
public:
    int largestComponentSize(const vector<int> &nums) {
        const auto n = (int) nums.size();
        int parent[n];
        int set_size[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        unordered_map<int, vector<int>> factor_nums;  // 存储以因子a为约数的数
        for (int i = 0; i < n; ++i) {
            const auto &x = nums[i];
            for (int a = 1; a <= x / a; ++a) {
                if (x % a) {
                    continue;
                }
                factor_nums[x / a].emplace_back(i);
                if (a > 1) {
                    factor_nums[a].emplace_back(i);
                }
            }
        }
        int ans = 1;
        for (const auto &item: factor_nums) {
            for (int i = 1; i < (int) item.second.size(); ++i) {
                auto a = findRoot(item.second[i - 1], parent);
                auto b = findRoot(item.second[i], parent);
                if (a == b) {
                    continue;
                }
                b = mergeSets(a, b, parent, set_size);
                ans = max(set_size[b], ans);
            }
        }
        return ans;
    }

private:
    static int findRoot(int x, int parent[]) {
        if (x != parent[x]) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }

    static int mergeSets(int a, int b, int parent[], int set_size[]) {
        if (a == b) {
            return -1;
        }
        if (set_size[a] < set_size[b]) {
            set_size[b] += set_size[a];
            parent[a] = b;
            return b;
        }
        set_size[a] += set_size[b];
        parent[b] = a;
        return a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0952_H
