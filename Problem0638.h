//
// Created by Fengwei Zhang on 2/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0638_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0638_H

#include <vector>
#include <map>
#include <cmath>
#include <cstring>

using namespace std;

class Solution {
    // 经典算法，必须掌握：记忆化搜索 + 状态压缩
    // https://leetcode-cn.com/problems/shopping-offers/solution/da-li-bao-by-leetcode-solution-p1ww/
public:
    int shoppingOffers(const vector<int> &price, const vector<vector<int>> &special, const vector<int> &needs) {
        const auto n = (int) price.size();
        vector<vector<int>> valid_special;  // 过滤不需要计算的大礼包，只保留需要计算的大礼包
        for (const auto &sp: special) {
            int counter = 0;
            int total = 0;
            for (int i = 0; i < n; ++i) {
                counter += sp[i];
                total += sp[i] * price[i];
            }
            if (counter > 0 && total > sp[n]) {  // 比原价低，有效
                valid_special.emplace_back(sp);
            }
        }
        map<vector<int>, int> memo;  // map支持使用vector为键
        return dfs(price, needs, valid_special, n, memo);
    }

private:
    // 记忆化搜索计算满足购物清单所需花费的最低价格
    int dfs(const vector<int> &price,
            const vector<int> &needs,
            const vector<vector<int>> &valid_special,
            const int n, map<vector<int>, int> &memo) {
        if (memo.count(needs)) {
            return memo[needs];
        }
        int minimal = 0;
        for (int i = 0; i < n; ++i) {
            minimal += needs[i] * price[i]; // 不购买任何大礼包，原价购买购物清单中的所有物品
        }
        for (const auto &offer: valid_special) {
            auto offer_price = offer[n];
            vector<int> next_needs;  // 计算下一步要购买的商品
            for (int i = 0; i < n; ++i) {
                if (offer[i] > needs[i]) { // 不能购买超出购物清单指定数量的物品
                    break;
                }
                next_needs.emplace_back(needs[i] - offer[i]);
            }
            if ((int) next_needs.size() == n) { // 可以购买大礼包
                minimal = min(minimal, dfs(price, next_needs, valid_special, n, memo) + offer_price);
            }
        }
        memo[needs] = minimal;
        return memo[needs];
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0638_H
