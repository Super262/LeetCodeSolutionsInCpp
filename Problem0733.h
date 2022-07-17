//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0733_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0733_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
    // 从起点(sx,sy)开始BFS，将所有搜索到的点染色
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sx, int sy, int nc) {
        if (image[sx][sy] == nc) {
            return image;
        }
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {-1, 0, 1, 0};
        const auto sc = image[sx][sy];
        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        image[sx][sy] = nc;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                auto nx = t.first + dx[i];
                auto ny = t.second + dy[i];
                if (nx < 0 || ny < 0 || nx >= image.size() || ny >= image[0].size() || image[nx][ny] == nc ||
                    image[nx][ny] != sc) {
                    continue;
                }
                image[nx][ny] = nc;
                q.emplace(nx, ny);
            }
        }
        return image;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0733_H
