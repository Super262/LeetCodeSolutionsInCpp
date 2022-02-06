//
// Created by Fengwei Zhang on 11/12/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0187_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0187_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 经典算法，必须背诵
    // 字符串哈希
public:
    vector<string> findRepeatedDnaSequences(const string &s) {
        const auto n = (int) s.size();
        unsigned long long hash[n + 1];
        unsigned long long factor[n + 1];
        hash[0] = 0;
        factor[0] = 1;
        for (int i = 1; i <= n; ++i) {  // 牢记这个运算过程
            hash[i] = hash[i - 1] * P + s[i - 1];
            factor[i] = factor[i - 1] * P;
        }
        unordered_map<unsigned long long, int> counter;
        vector<string> res;
        for (int i = 1; i + 10 - 1 <= n; ++i) {
            auto j = i + 10 - 1;
            auto x = hash[j] - hash[i - 1] * factor[j - i + 1];  // 牢记此公式
            if (counter[x] == 1) {  // 只有更新前哈希等于1的子串是正确结果，避免结果集包含重复字符串
                res.emplace_back(s.substr(i - 1, 10));
            }
            ++counter[x];
        }
        return res;
    }

private:
    static const unsigned int P = 13131;
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0187_H
