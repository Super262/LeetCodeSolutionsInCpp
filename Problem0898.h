
//
// Created by Fengwei Zhang on 4/10/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0898_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0898_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // f[i]：所有以a[i]结尾的子数组中所有元素"或运算"得到的结果；这里利用了或运算"只增不减"的特点
    // 虽然以a[i]结尾的子数组有很多个，但它们所包含的元素进行"或运算"的到的结果并不多
    // 计算f[i]时，只需使用f[i - 1]，因此我们只需要保存两组运算结果
public:
    int subarrayBitwiseORs(const vector<int> &arr) {
        unordered_set<int> prev;  // f[i - 1]
        unordered_set<int> cur;  // f[i]
        unordered_set<int> ans;
        for (const auto &y: arr) {
            cur.insert(y);
            for (const auto &x: prev) {
                cur.insert(x | y);
            }
            for (const auto &x: cur) {
                ans.insert(x);
            }
            prev = cur;
            cur.clear();
        }
        return (int) ans.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0898_H
