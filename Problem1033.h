//
// Created by Fengwei Zhang on 4/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1033_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1033_H

#include <vector>

using namespace std;

class Problem1033 {
    // 分情况讨论，注意细节
public:
    vector<int> numMovesStones(int a, int b, int c) {
        // 手动排序
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }
        vector<int> ans(2);
        // 求最小值
        if (b - a == 1 && c - b == 1) {  // 两边无需移动
            ans[0] = 0;
        } else if (b - a == 1 || c - b == 1) {  // 一边无需移动
            ans[0] = 1;
        } else if (b - a == 2 || c - b == 2) {  // 可以插入中间
            ans[0] = 1;
        } else {  // 两边都需要移动
            ans[0] = 2;
        }
        ans[1] = c - a - 2;  // 最大值为三者间空位长度之和
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1033_H
