//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1041_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1041_H

#include <string>

using namespace std;

class Problem1041 {
    // 1轮执行结束后，方向与初始方向一致（向北），并且不是位于初始地点（0，0），那么将永远不会循环；否则，一定会产生循环
public:
    bool isRobotBounded(const string &instructions) {
        const int dx[4] = {0, -1, 0, 1};
        const int dy[4] = {1, 0, -1, 0};
        int x = 0;
        int y = 0;
        int i = 0;
        for (const auto &c: instructions) {
            if (c == 'G') {
                x += dx[i];
                y += dy[i];
                continue;
            }
            if (c == 'L') {
                i = (i + 1) % 4;
                continue;
            }
            if (c == 'R') {
                i = ((i - 1) % 4 + 4) % 4;
            }
        }
        return (!x && !y) || i;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1041_H
