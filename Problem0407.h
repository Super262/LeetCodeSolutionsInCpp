//
// Created by Fengwei Zhang on 11/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0407_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0407_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 注意理解思想！详见视频题解！背诵代码！
    // 由外向内、由小及大，依次累计高度差
public:
    int trapRainWater(const vector<vector<int>> &heightMap) {
        const int n = (int) heightMap.size();
        const int m = (int) heightMap[0].size();
        priority_queue<Cell> heap;  // 默认为小根堆
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {  // 左、右边界
            visited[i][0] = true;
            visited[i][m - 1] = true;
            heap.push({heightMap[i][0], i, 0});
            heap.push({heightMap[i][m - 1], i, m - 1});
        }
        for (int i = 1; i < m - 1; ++i) { // 上、下边界（不包含左、右边界中的4个点）
            visited[0][i] = true;
            visited[n - 1][i] = true;
            heap.push({heightMap[0][i], 0, i});
            heap.push({heightMap[n - 1][i], n - 1, i});
        }
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        int res = 0;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            res += t.h - heightMap[t.x][t.y];
            for (int k = 0; k < 4; ++k) {
                auto nx = t.x + dx[k];
                auto ny = t.y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
                    continue;
                }
                heap.push({max(heightMap[nx][ny], t.h), nx, ny});
                visited[nx][ny] = true;
            }
        }
        return res;
    }

private:
    struct Cell {
        int h;
        int x;
        int y;

        bool operator<(const Cell &t) const {
            return h > t.h;  // 题目使用小根堆，所以这里使用大于号
        }
    };
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0407_H