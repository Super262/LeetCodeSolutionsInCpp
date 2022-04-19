//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0975_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0975_H

#include <vector>
#include <map>
#include <cstring>

using namespace std;

class Solution {
    // 预处理不同索引i、j（i < j）间的跳跃关系，从终点向前递推
    // 利用map的lower_bound和upper_bound来查找最小值；从后向前遍历来保证结果最近
public:
    int oddEvenJumps(const vector<int> &arr) {
        const auto n = (int) arr.size();
        bool f[n][2];  // f[i][0]：偶数跳可达终点，f[i][1]：奇数跳可达终点
        map<int, int> val_idx;
        memset(f, 0, sizeof f);
        f[n - 1][0] = true;
        f[n - 1][1] = true;
        val_idx[arr[n - 1]] = n - 1;
        int ans = 1;
        for (auto i = n - 2; i >= 0; --i) {
            auto it = val_idx.lower_bound(arr[i]);
            if (it != val_idx.end() && f[it->second][0]) {  // 存在j，满足arr[j] >= arr[i]（j > i）
                f[i][1] = true;  // 若j可以偶数跳到终点，i可跳到终点
                ++ans;  // 只有f[i][1]成立，我们才更新答案
            }
            it = val_idx.upper_bound(arr[i]);  // 第二次查找，必不可少
            if (it != val_idx.begin()) {  // 存在j，满足arr[j] <= arr[i]（j > i）
                --it;
                f[i][0] = f[it->second][1];
            }
            val_idx[arr[i]] = i;
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0975_H
