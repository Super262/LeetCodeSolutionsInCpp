//
// Created by Fengwei Zhang on 11/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0134_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0134_H

#include <vector>

using namespace std;

class Solution {
    // 经典算法，直接背诵：若ed不可达，[st, ed]所有点都不是合法起点
    // https://www.acwing.com/video/1499/
public:
    int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
        const int n = (int) gas.size();
        int st = 0;
        while (st < n) {  // 枚举起点
            int remainder = 0;  // 剩余油量
            int steps = 0;  // 前进的步数
            while (steps < n) {
                auto ed = (st + steps) % n;  // 终点
                remainder += gas[ed] - cost[ed];
                if (remainder < 0) {
                    break;
                }
                ++steps;
            }
            if (steps == n) {
                return st;
            }
            st += steps + 1;
        }
        return -1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0134_H
