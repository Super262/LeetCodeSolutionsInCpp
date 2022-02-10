//
// Created by Fengwei Zhang on 2/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0649_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0649_H

#include <string>
#include <queue>

using namespace std;

class Solution {
    // 经典贪心，直接背诵：优先封禁座次靠前的议员
public:
    string predictPartyVictory(const string &senate) {
        queue<int> rs;  // 从前向后保存R的位置
        queue<int> ds;  // 从前向后保存D的位置
        for (int i = 0; i < (int) senate.size(); ++i) {
            if (senate[i] == 'R') {
                rs.emplace(i);
            } else {
                ds.emplace(i);
            }
        }
        const auto n = (int) senate.size();
        while (!rs.empty() && !ds.empty()) {
            if (rs.front() < ds.front()) {  // R可以先行使权力，当前议员可进入下一轮投票
                rs.emplace(rs.front() + n);
            } else { // D可以先行使权力，当前议员可进入下一轮投票
                ds.emplace(ds.front() + n);
            }
            rs.pop();
            ds.pop();
        }
        if (rs.empty()) {
            return "Dire";
        }
        return "Radiant";
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0649_H
