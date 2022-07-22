//
// Created by Fengwei Zhang on 2/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0752_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0752_H

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Problem0752 {
    // BFS，从起点st="0000"开始，每次变换1个字符，跳过被访问过的位置和"死亡数字"，直至抵达终点ed，返回所需步数
public:
    int openLock(const vector<string> &dead_ends, const string &ed) {
        string st = "0000";
        queue<string> q;
        unordered_map<string, int> dist;
        unordered_set<string> visited(dead_ends.begin(), dead_ends.end());
        if (visited.count(st)) {
            return -1;
        }
        visited.insert(st);
        q.emplace(st);
        dist[st] = 0;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            auto d = dist[t];
            if (t == ed) {
                return d;
            }
            for (int i = 0; i < (int) t.size(); ++i) {
                auto ch = t[i];
                for (int j = -1; j <= 1; ++j) {
                    auto nch = (((ch - '0') + j) % 10 + 10) % 10 + '0';
                    auto nt = t;
                    nt[i] = (char) nch;
                    if (visited.count(nt)) {
                        continue;
                    }
                    visited.insert(nt);
                    dist[nt] = d + 1;
                    q.emplace(nt);
                }
            }
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0752_H
