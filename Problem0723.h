
//
// Created by Fengwei Zhang on 7/14/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0723_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0723_H

#include <vector>
#include <cstring>

using namespace std;

class Problem0723 {
    // 首先，合并每行的相邻糖果（相同区段长度大于2），记录每个位置(i,j)的原值为visited[i*n+j]
    // 然后，根据board和visited，合并每列的相邻糖果（相同区段长度大于2）
    // 最后，将在高处的糖果board[l][j]"下滑到"board[r][j]（l<=r）；注意细节：l可能等于r，因此我们不能直接将board[l][j]设置为"0"，应执行类似"swap"的操作
public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board) {
        int visited[board.size() * board[0].size()];
        while (true) {
            memset(visited, 0, sizeof visited);
            auto a = modifyRow(board, visited);
            auto b = modifyColumn(board, visited);
            moveCandies(board);
            if (!a && !b) {
                break;
            }
        }
        return board;
    }

private:
    bool modifyRow(vector<vector<int>> &board, int visited[]) {
        bool ans = false;
        const auto m = (int) board.size();
        const auto n = (int) board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int l = 0; l < n; ++l) {
                if (!board[i][l]) {  // 跳过空位
                    continue;
                }
                auto r = l;
                while (r < n && board[i][l] == board[i][r]) {  // 探索区段长度
                    ++r;
                }
                if (r - l > 2) {  // 长度大于2，符合要求
                    for (int j = l; j < r; ++j) {
                        visited[i * n + j] = board[i][j];
                        board[i][j] = 0;
                    }
                    ans = true;
                }
                l = r - 1;
            }
        }
        return ans;
    }

    bool modifyColumn(vector<vector<int>> &board, const int visited[]) {
        bool ans = false;
        const auto m = (int) board.size();
        const auto n = (int) board[0].size();
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < m; ++l) {
                int a = board[l][j];
                if (visited[l * n + j]) {  // 若曾被发现，取初值
                    a = visited[l * n + j];
                }
                if (!a) {  // 跳过空位
                    continue;
                }
                auto r = l;
                while (r < m) {  // 探索区段长度
                    int b = board[r][j];
                    if (visited[r * n + j]) {
                        b = visited[r * n + j];
                    }
                    if (a != b) {
                        break;
                    }
                    ++r;
                }
                if (r - l > 2) {  // 长度大于2，符合要求
                    for (int i = l; i < r; ++i) {
                        board[i][j] = 0;
                    }
                    ans = true;
                }
                l = r - 1;
            }
        }
        return ans;
    }

    void moveCandies(vector<vector<int>> &board) {
        const auto m = (int) board.size();
        const auto n = (int) board[0].size();
        for (int j = 0; j < n; ++j) {
            auto r = m - 1;
            for (int l = m - 1; l >= 0; --l) {
                if (!board[l][j]) {
                    continue;
                }
                auto t = board[l][j];  // 细节，应对l=r的情况
                board[l][j] = 0;
                board[r][j] = t;
                --r;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0723_H
