//
// Created by Fengwei Zhang on 4/9/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0888_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0888_H

#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
    // 设Alice拥有的糖果数量是s1、Bob拥有的糖果数量是s2；若Alice将a和Bob的b交换后，两者拥有的糖果数量一致
    // 因此，(s1 - a + b) = (s2 - b + a)，a - b = (s1 - s2) / 2
public:
    vector<int> fairCandySwap(const vector<int> &alice, const vector<int> &bob) {
        auto s1 = accumulate(alice.begin(), alice.end(), 0);
        auto s2 = accumulate(bob.begin(), bob.end(), 0);
        if ((s1 - s2) % 2) {
            return {};
        }
        const auto d = (s1 - s2) / 2;
        unordered_map<int, int> as;
        for (const auto &x: alice) {
            ++as[x];
        }
        for (const auto &b: bob) {
            if (as.count(b + d)) {
                return {b + d, b};
            }
        }
        return {};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0888_H
