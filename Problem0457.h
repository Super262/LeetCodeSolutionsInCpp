//
// Created by Fengwei Zhang on 1/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0457_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0457_H

#include <vector>
#include <cmath>

using namespace std;

class Solution {
    // 图论经典题：题目要求找同向环，我们可以BFS并忽略回边
    // 要求额外空间O(1)，因此需要利用原数组判重；同向边引起自环：步数 % n == 0
public:
    bool circularArrayLoop(vector<int> &nums) {
        const int BASE = 1000;  // nums所有数据不超过1000
        const auto n = (int) nums.size();
        for (int st = 0; st < n; ++st) {
            if (nums[st] > BASE) {  // 若之前从nums[i]出发不能找到环，现在我们跳过i
                continue;
            }
            auto j = st;
            auto direction = nums[j] > 0;  // 同向环，需确定方向
            auto label = BASE + st + 1;  // 当前遍历阶段的访问标记
            int last_steps;  // 上一次移动的步数
            do {
                auto k = ((nums[j] + j) % n + n) % n;
                last_steps = abs(nums[j]);
                nums[j] = label;
                j = k;
            } while (nums[j] < BASE && direction == (nums[j] > 0));  // 当前位置有效且方向不变
            if (last_steps % n && nums[j] == label) {  // 判定last_steps不是n的倍数
                return true;
            }
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0457_H
