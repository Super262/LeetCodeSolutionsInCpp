//
// Created by Fengwei Zhang on 3/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0782_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0782_H

#include <vector>
#include <unordered_set>

using namespace std;

class Problem0782 {
    // 我们发现：若行i和行j相同，那么交换它们的任意2列，行i和行j仍然相同；对于列i和列j亦是如此；因此，所有行操作、列操作不会改变行、列的种类数
    // 由于最终状态只有2种不同的行和2种不同的列，输入状态也应只有2种不同的行和2种不同的列；另外，由于最终状态的2种行/列是互补的，交换操作不改变互补性
    // 因此，输入状态中的2种行/列也应是互补的；另外，行操作和列操作是独立的，即对于矩阵中的任意位置(i,j)，多个操作的先后顺序不改变最终的值
    // 所以，我们可以先做行操作，再做列操作；另外，假设当前有r1、r2两种行，将r1变为t1后，r2会随之变为和t1互补的t2；因此，我们只要考虑在r1上的操作，同理c1和c2
    // 对于任意2行/列的状态值s1、s2，若s1、s2有k个位置不同，将s1、s2调整到相同的最少的操作次数是k/2：每次交换可改变2位
    // 举例：将行"0011"转化为行"1100"，只需执行2次列交换即可
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
        int t1 = 0;  // t1、t2是最终状态中2种不同的行/列
        for (int i = 0; i < n; i += 2) {
            t1 |= 1 << i;
        }
        int t2 = ((1 << n) - 1) ^ t1;
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
