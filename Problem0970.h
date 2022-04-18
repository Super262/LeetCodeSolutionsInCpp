//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0970_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0970_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 通过分析，我们发现：若x^i <= bound，i <= logx(bound)；因此，我们直接枚举所有可能组合
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for (int a = 1; a <= bound; a *= x) {
            for (int b = 1; a + b <= bound; b *= y) {
                s.insert(a + b);
                if (y == 1) {  // 必须特判，否则会死循环
                    break;
                }
            }
            if (x == 1) {
                break;
            }
        }
        return {s.begin(), s.end()};
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0970_H
