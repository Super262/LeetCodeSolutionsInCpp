//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0839_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0839_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 将一组相似的字符串视为一个集合，答案是集合的数量
public:
    int numSimilarGroups(const vector<string> &strs) {
        const auto n = (int) strs.size();
        int parent[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!isSimilar(strs[i], strs[j])) {
                    continue;
                }
                auto pa = findRoot(i, parent);
                auto pb = findRoot(j, parent);
                if (pa == pb) {
                    continue;
                }
                parent[pb] = pa;
                --ans;
            }
        }
        return ans;
    }

private:
    bool isSimilar(const string &a, const string &b) {
        if (a.size() != b.size()) {
            return false;
        }
        int selected[3];
        int j = 0;  // 不同字符的个数
        for (int i = 0; i < (int) a.size(); ++i) {
            if (a[i] == b[i]) {
                continue;
            }
            selected[j] = i;
            ++j;
            if (j > 2) {  // 及时终止，避免无效计算
                return false;
            }
        }
        if (j == 0) {
            return true;
        }
        auto x = selected[0];
        auto y = selected[1];
        return a[x] == b[y] && a[y] == b[x];
    }

    int findRoot(int x, int parent[]) {
        if (parent[x] != x) {
            parent[x] = findRoot(parent[x], parent);
        }
        return parent[x];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0839_H
