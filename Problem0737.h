//
// Created by Fengwei Zhang on 7/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0737_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0737_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 并查集，我们将相似的两个单词合并到同一个集合；我们要先将单词离散化，建立"单词-数字"映射，再建立并查集
    // 判断s1、s2是否相似，就是判断s1[i]和s2[i]是否相等，或者在1个集合中；注意边界情况：similarPairs为空或s1.size()!=s2.size()
public:
    bool areSentencesSimilarTwo(const vector<string> &s1,
                                const vector<string> &s2,
                                const vector<vector<string>> &similarPairs) {
        if (s1.size() != s2.size()) {
            return false;
        }
        if (similarPairs.empty()) {
            return s1 == s2;
        }
        unordered_map<string, int> wordIdx;
        for (int i = 0, j = 0; j < (int) similarPairs.size(); ++j) {
            const auto &p = similarPairs[j];
            if (wordIdx.count(p[0])) {
                continue;
            }
            wordIdx[p[0]] = i;
            ++i;
            if (wordIdx.count(p[1])) {
                continue;
            }
            wordIdx[p[1]] = i;
            ++i;
        }
        const auto n = (int) wordIdx.size();
        int parent[n];
        int set_size[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            set_size[i] = 1;
        }
        for (const auto &p: similarPairs) {
            mergeSets(findRoot(wordIdx[p[0]], parent), findRoot(wordIdx[p[1]], parent), parent, set_size);
        }
        for (int i = 0; i < (int) s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            if (!wordIdx.count(s1[i]) || !wordIdx.count(s2[i])) {
                return false;
            }
            auto pa = findRoot(wordIdx[s1[i]], parent);
            auto pb = findRoot(wordIdx[s2[i]], parent);
            if (pa != pb) {
                return false;
            }
        }
        return true;
    }

private:
    int findRoot(int x, int parent[]) {
        auto u = x;
        while (parent[u] != u) {
            u = parent[u];
        }
        while (parent[x] != u) {
            auto p = parent[x];
            parent[x] = u;
            x = p;
        }
        return u;
    }

    int mergeSets(int pa, int pb, int parent[], int set_size[]) {
        if (pa == pb) {
            return -1;
        }
        if (set_size[pa] > set_size[pb]) {
            set_size[pa] += set_size[pb];
            parent[pb] = pa;
            return pa;
        }
        set_size[pb] += set_size[pa];
        parent[pa] = pb;
        return pb;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0737_H
