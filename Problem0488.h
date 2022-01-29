//
// Created by Fengwei Zhang on 1/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0488_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0488_H

#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
    // 记忆化搜索 + 剪枝：https://leetcode-cn.com/problems/zuma-game/solution/zu-ma-you-xi-by-leetcode-solution-lrp4/
    // 只在以下两种情况放置新球：当前球颜色与后面的球的颜色相同；当前后颜色相同且与当前颜色不同
public:
    int findMinStep(const string &board, const string &hand) {
        unordered_map<string, int> prev_state;
        auto answer = dfs(board, hand, prev_state);
        if (answer == INF) {
            return -1;
        }
        return answer;
    }

private:
    int dfs(const string &board, const string &hand, unordered_map<string, int> &prev_state) {
        if (board.empty()) {
            return 0;
        }
        auto key = board + '_' + hand;  // 用2个关键字查询
        if (prev_state.count(key)) {
            return prev_state[key];
        }
        int answer = INF;
        for (int i = 0; i < hand.size(); ++i) {
            for (int j = 0; j <= board.size(); ++j) {  // 尝试放置球在board[j-1]和board[j]之间
                bool selected = false;
                if (j < board.size() && board[j] == hand[i]) {
                    selected = true;  // 当前球颜色与后面的球的颜色相同
                }
                if (j > 0 && j < board.size() && board[j - 1] == board[j] && board[j] != hand[i]) {
                    selected = true;  // 前后颜色相同且与当前颜色不同
                }
                if (!selected) {
                    continue;
                }
                auto nb = board.substr(0, j) + hand[i] + board.substr(j);
                prune(nb, j);
                auto nh = hand.substr(0, i) + hand.substr(i + 1);
                answer = min(answer, 1 + dfs(nb, nh, prev_state));
            }
        }
        prev_state[key] = answer;
        return answer;
    }

    void prune(string &s, int x) {  // 删除3个以上的连续字符
        while (x >= 0 && x < s.size()) {
            char c = s[x];
            auto l = x, r = x;
            while (l >= 0 && s[l] == c) {
                --l;
            }
            while (r < s.size() && s[r] == c) {
                ++r;
            }
            if (r - l - 1 >= 3) {
                s.erase(l + 1, r - l - 1);
                x = l >= 0 ? l : r;
            } else {
                break;
            }
        }
    }

    const int INF = 0x3f3f3f3f;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0488_H