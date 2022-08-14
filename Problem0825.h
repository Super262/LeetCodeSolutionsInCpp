//
// Created by Fengwei Zhang on 4/1/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0825_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0825_H

#include <vector>
#include <unordered_map>

using namespace std;

class Problem0825 {
    // 这里采用求补集的思想：我们设置答案ans的初值为n*n，再从答案中减去不符合要求的部分；设年龄x的频率是f[x]
    // 不符合要求的部分：(1) 若年龄x、y满足题意中的违例，ans-=f[x]*f[y]；(2) 有多人年龄均为x，ans-=f[x]（每个人不能给自己发请求）
public:
    int numFriendRequests(const vector<int> &ages) {
        const auto n = (int) ages.size();
        unordered_map<int, int> f;
        for (const auto &x: ages) {
            ++f[x];
        }
        auto ans = n * n;
        for (const auto &x: f) {
            for (const auto &y: f) {
                if (y.first <= 0.5 * x.first + 7 || y.first > x.first || (y.first > 100 && x.first < 100)) {
                    ans -= x.second * y.second;
                    continue;
                }
                if (y.first == x.first) {
                    ans -= x.second;
                }
            }
        }
        return ans;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0825_H
