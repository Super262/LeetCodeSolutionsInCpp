//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1041_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1041_H

#include <string>

using namespace std;

class Solution {
    // 初始时向北，枚举指令的每个操作，若可以回到起点(0,0)，返回true
    // 若未回到起点，观察最后的方向：朝北，返回false；向东，未来会经历转向，会回到起点；向西、向南同理，返回false
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
        return (!x && !y) || i;  // 回到原点或朝北，返回true
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1041_H
