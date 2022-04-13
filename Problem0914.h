//
// Created by Fengwei Zhang on 4/13/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0914_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0914_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 统计每种纸牌i的个数counter[i]，再求出它们的最大公约数x，判断x是否大于等于2
public:
    bool hasGroupsSizeX(const vector<int> &deck) {
        unordered_map<int, int> counter;
        for (const auto &x: deck) {
            counter[x]++;
        }
        auto d = 0;
        for (const auto &item: counter) {
            d = gcd(d, item.second);
        }
        return d >= 2;
    }

private:
    static int gcd(int a, int b) {
        while (b) {
            auto t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0914_H
