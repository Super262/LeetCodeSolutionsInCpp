//
// Created by Fengwei Zhang on 4/13/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0914_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0914_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
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
