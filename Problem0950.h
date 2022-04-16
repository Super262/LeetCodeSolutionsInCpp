//
// Created by Fengwei Zhang on 4/16/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0950_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0950_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    // 直接模拟，在索引i处放纸牌，将(i+1)压入队尾
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        for (int i = 0; i < (int) deck.size(); ++i) {
            q.emplace(i);
        }
        int i = 0;
        vector<int> ans(deck);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            ans[u] = deck[i];
            ++i;
            if (!q.empty()) {
                auto t = q.front();
                q.pop();
                q.emplace(t);
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0950_H
