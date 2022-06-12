//
// Created by Fengwei Zhang on 6/12/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0489_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0489_H

#include <unordered_map>
#include <unordered_set>
#include "robot.h"

using namespace std;

class Solution {
    // 从(0.0)点向4个方向（顺时针）尝试DFS，标记被清洁的点；不能用BFS，因为我们无法记录robot的状态
public:
    void cleanRoom(Robot &robot) {
        unordered_map<int, unordered_set<int>> visited;  // 集合判重
        dfs(robot, 0, 0, 0, visited);
    }

private:
    const int dx[4] = {-1, 0, 1, 0};  // 顺时针的4个方向（上、右、下、左）
    const int dy[4] = {0, 1, 0, -1};

    void dfs(Robot &robot, int x, int y, int i, unordered_map<int, unordered_set<int>> &visited) {
        visited[x].insert(y);
        robot.clean();
        for (int j = 0; j < 4; ++j, robot.turnRight()) {
            auto ni = (i + j) % 4;
            auto nx = x + dx[ni];
            auto ny = y + dy[ni];
            if (visited.count(nx) && visited[nx].count(ny)) {
                continue;
            }
            if (!robot.move()) {
                continue;
            }
            dfs(robot, nx, ny, ni, visited);
            goBack(robot);
        }
    }

    void goBack(Robot &robot) {  // 返回上个位置、方向
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0489_H
