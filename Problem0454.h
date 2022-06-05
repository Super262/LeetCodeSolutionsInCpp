//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0454_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0454_H

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    // 先记录(a+b)所有可能的取值的频率，再枚举(c+d)的所有可能值，累计(a+b)=(-c-d)的频率
    // 扩展：kSum问题，输入为k个数组，解法详见注释
public:
    int fourSumCount(const vector<int> &a, const vector<int> &b, const vector<int> &c, const vector<int> &d) {
        unordered_map<int, int> counter;
        for (const auto &x: a) {
            for (const auto &y: b) {
                ++counter[x + y];
            }
        }
        int ans = 0;
        for (const auto &x: c) {
            for (const auto &y: d) {
                if (!counter.count(-(x + y))) {
                    continue;
                }
                ans += counter[-(x + y)];
            }
        }
        return ans;
    }
};

/*class Solution {
    // 设输入序列的个数为k，枚举所有从前k/2个序列中选取2/k个数的组合，记录每个和的频率
    // 递归枚举后面k/2个序列，统计"补集"的个数
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        return kSumCount(vector<vector<int>>() = {A, B, C, D});
    }

private:
    int kSumCount(const vector<vector<int>> &lists) {
        unordered_map<int, int> counter;
        addToHash(lists, counter, 0, 0);
        return countComplements(lists, counter, (int) lists.size() / 2, 0);
    }

    void addToHash(const vector<vector<int>> &lists, unordered_map<int, int> &counter, int i, int sum) {
        if (i == (int) lists.size() / 2) {
            ++counter[sum];
            return;
        }
        for (int a: lists[i]) {
            addToHash(lists, counter, i + 1, sum + a);
        }
    }

    int countComplements(const vector<vector<int>> &lists, unordered_map<int, int> &m, int i, int complement) {
        if (i == (int) lists.size()) {
            auto it = m.find(complement);
            return it == end(m) ? 0 : it->second;
        }
        int ans = 0;
        for (const auto &a: lists[i]) {
            ans += countComplements(lists, m, i + 1, complement - a);
        }
        return ans;
    }
};*/

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0454_H
