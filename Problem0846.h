//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0846_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0846_H

#include <vector>
#include <set>

using namespace std;

class Solution {
    // 设S是手中所有牌的数字的集合，x为S中的最小值，x必定存在于某个顺子中
    // 因此，我们持续拿出序列{x, x+1, ..., x+group_size-1}，直至S为空集
public:
    bool isNStraightHand(const vector<int> &hand, int group_size) {
        multiset<int> s(hand.begin(), hand.end());
        if (s.size() % group_size) {  // 不能整除，非法
            return false;
        }
        while (!s.empty()) {
            auto x = *s.begin();  // 找到最小值
            for (int i = 0; i < group_size; ++i) {
                const auto &it = s.find(x + i);
                if (it == s.end()) {  // 没有顺子，非法
                    return false;
                }
                s.erase(it);
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0846_H
