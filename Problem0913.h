//
// Created by Fengwei Zhang on 4/12/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0913_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0913_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 自底向上，拓扑排序
    // https://leetcode-cn.com/problems/cat-and-mouse/solution/mao-he-lao-shu-by-leetcode-solution-444x/
public:
    int catMouseGame(const vector<vector<int>> &graph) {
        const auto n = (int) graph.size();
        int degrees[n][n][2];
        memset(degrees, 0, sizeof degrees);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                degrees[i][j][MOUSE_TURN] = (int) graph[i].size();
                degrees[i][j][CAT_TURN] = (int) graph[j].size();
            }
        }
        for (const int &j: graph[0]) {
            for (int i = 0; i < n; i++) {
                --degrees[i][j][CAT_TURN];
            }
        }
        queue<Node> q;
        int f[n][n][2];
        memset(f, 0, sizeof f);
        for (int j = 1; j < n; j++) {
            f[0][j][MOUSE_TURN] = MOUSE_WIN;
            f[0][j][CAT_TURN] = MOUSE_WIN;
            q.emplace(0, j, MOUSE_TURN);
            q.emplace(0, j, CAT_TURN);
        }
        for (int i = 1; i < n; i++) {
            f[i][i][MOUSE_TURN] = CAT_WIN;
            f[i][i][CAT_TURN] = CAT_WIN;
            q.emplace(i, i, MOUSE_TURN);
            q.emplace(i, i, CAT_TURN);
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            auto result = f[u.mouse][u.cat][u.turn];
            auto prev_states = getPrevStates(u.mouse, u.cat, u.turn, graph);
            for (const auto &p: prev_states) {
                auto prev_mouse = p.mouse;
                auto prev_cat = p.cat;
                auto prev_turn = p.turn;
                if (f[prev_mouse][prev_cat][prev_turn] != DRAW) {
                    continue;
                }
                bool can_win = (result == MOUSE_WIN && prev_turn == MOUSE_TURN) ||
                               (result == CAT_WIN && prev_turn == CAT_TURN);
                if (can_win) {
                    f[prev_mouse][prev_cat][prev_turn] = result;
                    q.emplace(prev_mouse, prev_cat, prev_turn);
                    continue;
                }
                --degrees[prev_mouse][prev_cat][prev_turn];
                if (degrees[prev_mouse][prev_cat][prev_turn] == 0) {
                    auto lose_result = prev_turn == MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
                    f[prev_mouse][prev_cat][prev_turn] = lose_result;
                    q.emplace(prev_mouse, prev_cat, prev_turn);
                }
            }
        }
        return f[1][2][MOUSE_TURN];
    }

private:
    const int MOUSE_TURN = 0;  // 老鼠先手
    const int CAT_TURN = 1;

    const int DRAW = 0;
    const int MOUSE_WIN = 1;
    const int CAT_WIN = 2;

    struct Node {
        int mouse;  // 老鼠的位置
        int cat;  // 猫的位置
        int turn; // 回合编号

        Node(int m, int c, int t) {
            mouse = m;
            cat = c;
            turn = t;
        }
    };

    vector<Node> getPrevStates(int mouse, int cat, int turn, const vector<vector<int>> &graph) {
        vector<Node> prev_states;
        auto prev_turn = turn == MOUSE_TURN ? CAT_TURN : MOUSE_TURN;
        if (prev_turn == MOUSE_TURN) {
            for (const int &prev_mouse: graph[mouse]) {
                prev_states.emplace_back(prev_mouse, cat, prev_turn);
            }
            return prev_states;
        }
        for (const int &prev_cat: graph[cat]) {
            if (prev_cat == 0) {
                continue;
            }
            prev_states.emplace_back(mouse, prev_cat, prev_turn);
        }
        return prev_states;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0913_H
