//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0433_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0433_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
    // BFS，搜索出可行的转化路径（start-> ... ->end），类似AcWing 845
public:
    int minMutation(const string &start, const string &end, const vector<string> &bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end)) {
            return -1;
        }
        const char parts[] = {'A', 'G', 'C', 'T'};
        queue<string> q;
        unordered_map<string, int> dist;
        dist[start] = 0;
        q.emplace(start);
        while (!q.empty()) {
            auto root = q.front();
            q.pop();
            auto rd = dist[root];
            if (root == end) {
                return rd;
            }
            for (auto &ch: root) {
                auto a = ch;
                for (const auto &p: parts) {
                    ch = p;
                    if (!dict.count(root) || dist.count(root)) {
                        continue;
                    }
                    q.emplace(root);
                    dist[root] = rd + 1;
                }
                ch = a;
            }
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0433_H
