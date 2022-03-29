//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0782_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0782_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 最终状态：只有2种不同的行，而且这2种行互补；由于我们只能交换2行/列，输入的数据至多有2种行/列
    // 对行的操作和对列的操作是相互独立的，因此我们可以分别思考行和列
    // 因此，本题的最终目标是计算将输入的每行/列转化为目标行/列的最小操作次数（注意，1次交换操作会改动2个位置的值）
public:
    int movesToChessboard(const vector<vector<int>> &board) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        const auto n = (int) board.size();
        for (int i = 0; i < n; ++i) {
            int r = 0;
            int c = 0;
            for (int j = 0; j < n; ++j) {
                r = (r << 1) | board[i][j];
                c = (c << 1) | board[j][i];
            }
            rows.insert(r);
            cols.insert(c);
        }
        if (rows.size() != 2 || cols.size() != 2) {  // 超过2种，无解
            return -1;
        }
        auto r1 = *rows.cbegin();
        auto r2 = *(++rows.cbegin());
        auto c1 = *cols.cbegin();
        auto c2 = *(++cols.cbegin());
        if ((r1 ^ r2) != (1 << n) - 1 || (c1 ^ c2) != (1 << n) - 1) {  // 两者不"互补"，无解
            return -1;
        }
        int t1 = 0;
        int t2;  // 2种目标状态
        for (int i = 0; i < n; i += 2) {
            t1 |= 1 << i;
        }
        t2 = ((1 << n) - 1) ^ t1;
        auto r_cost = min(countCost(r1, t1), countCost(r1, t2));  // 尝试2种目标值
        auto c_cost = min(countCost(c1, t1), countCost(c1, t2));
        auto ans = r_cost + c_cost;  // 由于r1和r2互补、c1和c2互补，所以r1/c1转变为t1/t2时，r2/c2也会变为t2/t1
        if (ans >= INF) {
            return -1;
        }
        return ans;
    }

private:
    int countOnes(int x) {
        int ans = 0;
        while (x) {
            ans += x & 1;
            x >>= 1;
        }
        return ans;
    }

    int countCost(int s, int t) {  // 计算从s变换到t所需的交换次数
        if (countOnes(s) != countOnes(t)) {  // s和t含1的数量不同，无解
            return INF;
        }
        return countOnes(s ^ t) / 2;
    }

    const int INF = 0x3f3f3f3f;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0782_H
