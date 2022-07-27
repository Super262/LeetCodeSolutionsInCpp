//
// Created by Fengwei Zhang on 2/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0756_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0756_H

#include <vector>
#include <string>

using namespace std;

class Problem0756 {
    // DFS，从底部开始，逐个枚举所有"三角形"，直到顶部
public:
    bool pyramidTransition(const string &bottom, const vector<string> &allowed) {
        vector<vector<vector<char>>> g(7, vector<vector<char>>(7, vector<char>()));  // g[A][B]表示AB的顶点
        for (const auto &s: allowed) {
            g[s[0] - 'A'][s[1] - 'A'].emplace_back(s[2]);
        }
        string top;
        return dfs(bottom, top, 0, g);
    }

private:
    bool dfs(const string &bottom, string &top, int idx, const vector<vector<vector<char>>> &g) {
        if (bottom.size() == 1) {  // 到达顶点
            return true;
        }
        if (idx == (int) bottom.size() - 1) {  // 探索上层
            string t;
            return dfs(top, t, 0, g);
        }
        for (const auto &ch: g[bottom[idx] - 'A'][bottom[idx + 1] - 'A']) {
            top.push_back(ch);  // 细节：不要传递top + ch到下层，会浪费大量时间用于拷贝
            if (dfs(bottom, top, idx + 1, g)) {
                return true;
            }
            top.pop_back();
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0756_H
