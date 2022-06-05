//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0464_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0464_H

#include <cstring>

using namespace std;

class Solution {
    // DFS，枚举所有可能被选择的数字，n位二进制数指示当前被选中的数
    // 先手获胜：当前状态必胜或下个状态必败
public:
    bool canIWin(int n, int target) {
        if (n * (n + 1) / 2 < target) {
            return false;
        }
        int state[1 << n];  // state[i]：-1，未被访问；1，必胜；0，必败
        memset(state, -1, sizeof state);
        return nextState(0, n, target, state) == 1;
    }

private:
    int nextState(int cur, int n, int target, int state[]) {
        if (state[cur] != -1) {
            return state[cur];
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((cur >> i) & 1) {
                sum += i + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if ((cur >> i) & 1) {
                continue;
            }
            if (sum + i + 1 >= target) {  // 先手选择数字(i+1)可以取胜，先手必胜
                state[cur] = 1;
                return state[cur];
            }
            if (!nextState(cur + (1 << i), n, target, state)) {  // 后手选择数字(i+1)必败，先手必胜
                state[cur] = 1;
                return state[cur];
            }
        }
        state[cur] = 0;
        return state[cur];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0464_H
