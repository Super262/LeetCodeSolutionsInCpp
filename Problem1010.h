//
// Created by Fengwei Zhang on 4/21/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1010_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1010_H

#include <vector>
#include <cstring>

using namespace std;

class Problem1010 {
    // 双指针 + 哈希表，统计同余数字的个数
public:
    int numPairsDivisibleBy60(const vector<int> &time) {
        int counter[60];
        memset(counter, 0, sizeof counter);
        int ans = 0;
        for (const int &t: time) {
            auto x = ((-t) % 60 + 60) % 60;
            ans += counter[x];
            counter[((t % 60) + 60) % 60]++;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1010_H
