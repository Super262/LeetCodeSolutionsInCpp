//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0517_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0517_H

#include <vector>

using namespace std;

class Solution {
    // 贪心算法，理解背诵：https://www.acwing.com/solution/content/413/
public:
    int findMinMoves(const vector<int> &machines) {
        int total = 0;
        for (const auto &x: machines) {
            total += x;
        }
        auto n = (int) machines.size();
        if (total % n) {
            return -1;
        }
        auto avg = total / n;
        int answer = 0, left_sum = 0, right_sum = total;
        for (int i = 0; i < n; ++i) {
            right_sum -= machines[i];
            auto r_to_l = max(0, i * avg - left_sum);
            auto l_to_r = max(0, (n - i - 1) * avg - right_sum);
            answer = max(answer, r_to_l + l_to_r);
            left_sum += machines[i];
        }
        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0517_H
