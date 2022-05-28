//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0407_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0407_H

#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
    // 设所有位置的初始高度为h(i,j)，最终高度为f(i,j)，最终结果ans是所有(f(i,j)-h(i,j))的和
    // 对于任意点(i,j)，有4个相邻位置，f(i,j)=max(h(i,j),min(f(i-1,j),f(i+1,j),f(i,j+1),f(i,j-1)))
    // 可以观察到，上述转移方程存在循环依赖（f(i,j)和f(i-1,j)相互依赖），不能看作传统的动态规划
    // 我们采取最短路算法解决此动态规划问题，类似Dijkstra算法，从边界点（f(i,j)=h(i,j)）开始处理，标记被访问的节点
    // 注意理解思想！详见视频题解！背诵代码！
public:
    int trapRainWater(const vector<vector<int>> &height_map) {
        const auto m = (int) height_map.size();
        const auto n = (int) height_map[0].size();
        priority_queue<Cell, vector<Cell>, greater<Cell>> heap;
        bool visited[m][n];
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < m; ++i) {  // 左、右边界
            visited[i][0] = true;
            visited[i][n - 1] = true;
            heap.push({height_map[i][0], i, 0});
            heap.push({height_map[i][n - 1], i, n - 1});
        }
        for (int i = 1; i < n - 1; ++i) { // 上、下边界（不包含左、右边界中的4个点）
            visited[0][i] = true;
            visited[m - 1][i] = true;
            heap.push({height_map[0][i], 0, i});
            heap.push({height_map[m - 1][i], m - 1, i});
        }
        const int dx[4] = {-1, 1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};
        int ans = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            ans += t.h - height_map[t.x][t.y];
            for (int k = 0; k < 4; ++k) {
                auto nx = t.x + dx[k];
                auto ny = t.y + dy[k];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                    continue;
                }
                heap.push({max(height_map[nx][ny], t.h), nx, ny});
                visited[nx][ny] = true;
            }
        }
        return ans;
    }

private:
    struct Cell {
        int h;
        int x;
        int y;

        bool operator>(const Cell &t) const {  // 配合小根堆
            return h > t.h;
        }
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0407_H
