//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1040_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1040_H

#include <vector>
#include <algorithm>

using namespace std;

class Problem1040 {
    // 贪心：找到坐标范围，依次枚举
    // 最大操作次数：若选择最左侧石子，可用空位为spaces{stones[1]:stones[n-1]}；
    //    若选择最左侧石子，可用空位为spaces{stones[0]:stones[n-2]}；最大操作次数为以上两者的最小值
    // 最小操作次数：若有m个石子几乎相邻，我们只需要操作k次就可以使这n个石子相邻，我们希望m尽可能大
    //    因此，我们遍历所有长度为n的区间，以找到最大的m（双指针）
    //    若m<=n-2，外侧至少剩余2个石子，符合搬移操作的要求（移到两个石子中间），我们可以用(n-m)次操作填满这m个石子左侧或右侧(n-m)个空位
    //    若m=n-1，外侧只剩1个石子：若这m个石子内部有空隙，只需进行1次操作；否则，m个石子紧密相连，需要2次操作：
    //    若外侧的那1个石子在左边，我们要将最右侧石子移动到x，x与这m个相连石子左部距离为1，再把最外侧石子放到x+1
public:
    vector<int> numMovesStonesII(vector<int> &stones) {
        sort(stones.begin(), stones.end());
        return {solveMin(stones), solveMax(stones)};
    }

private:
    int solveMin(const vector<int> &stones) {
        const auto n = (int) stones.size();
        int m = 0;
        for (int l = 0, r = 0; r < n; r++) {  // 遍历长度为n的窗口，求得最大的m
            while (l < r && stones[r] - stones[l] + 1 > n) {
                ++l;
            }
            m = max(m, r - l + 1);
        }
        if (m == n - 1) {
            if (stones[0] + n - 1 == stones[n - 2] || stones[1] + n - 1 == stones[n - 1]) {  // [0:n-2]或[1:n-1]有可用的空位
                return 1;
            }
            return 2;
        }
        return n - m;
    }

    int solveMax(const vector<int> &stones) {
        const auto n = (int) stones.size();
        int sum = 0;  // 先计算全部空位，再减去不可用的位置
        for (int i = 0; i < n - 1; i++) {
            sum += stones[i + 1] - stones[i] - 1;
        }
        sum -= min(stones[1] - stones[0] - 1, stones[n - 1] - stones[n - 2] - 1);
        return sum;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1040_H
