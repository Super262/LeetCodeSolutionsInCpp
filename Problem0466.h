//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0466_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0466_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // 找循环节，重复枚举s1，统计第i个s1顺次包含s2中字符的个数k，记录counter[i]=k；
public:
    int getMaxRepetitions(const string &s1, int n1, const string &s2, int n2) {
        vector<int> counter;
        unordered_map<int, int> cnt_idx;
        for (int i = 0, k = 0; i < n1; ++i) {  // i指示第(i+1)个s1，k指示与s2已匹配的字符个数
            for (const char &ch1: s1) {
                if (ch1 == s2[k % s2.size()]) {
                    ++k;
                }
            }
            counter.emplace_back(k);  // counter[i]：(i+1)*s1包含的s2中的字符的个数
            if (cnt_idx.count((int) (k % s2.size()))) {  // 曾匹配s2到相同位置
                auto a = i - cnt_idx[(int) (k % s2.size())];  // 这个周期（上个匹配到现在）包含a个s1
                auto b = k - counter[cnt_idx[(int) (k % s2.size())]];  // 这个周期可匹配b个s2中的字符
                auto x = (n1 - (i + 1)) / a;  // 设第(i+2)个s1到第n1个s1共包含x个完整周期，b*x为它们匹配的s2中字符的数量
                auto y = (n1 - (i + 1)) % a;
                for (int u = 0; u < y; ++u) {  // 计算除去x个完整周期后余下的部分可匹配多少字符
                    for (const char &ch1: s1) {
                        if (ch1 == s2[k % s2.size()]) {
                            ++k;
                        }
                    }
                }
                auto ans = x * b + k;  // k等于第1到第(i+1)个s1可匹配的s2中字符数量 + 除去x个完整周期后余下的部分可匹配的字符数量
                return (int) (ans / s2.size() / n2);
            }
            cnt_idx[(int) (k % s2.size())] = i;
        }
        if (counter.empty()) {
            return 0;
        }
        return (int) (counter.back() / s2.size() / n2);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0466_H
