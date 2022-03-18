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
    // 找循环节
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
            counter.emplace_back(k);  // counter[i]：(counter[i] * s1)包含的s2中的字符的个数
            if (cnt_idx.count((int) (k % s2.size()))) {  // 存在(counter[x] * s1)曾匹配到相同位置
                auto a = i - cnt_idx[(int) (k % s2.size())];  // 这个周期包含a个s1
                auto b = k - counter[cnt_idx[(int) (k % s2.size())]];  // 这个周期可匹配b个s2中的字符
                auto res = (n1 - (i + 1)) / a * b;  // 设第(i+2)个s1到第n1个s1共包含x个完整周期，b*x为它们匹配的s2中字符的数量
                for (int u = 0; u < (n1 - (i + 1)) % a; ++u) {  // 计算除去x个完整周期后余下的部分可匹配多少字符
                    for (const char &ch1: s1) {
                        if (ch1 == s2[k % s2.size()]) {
                            ++k;
                        }
                    }
                }
                res += k;  // k = 第1到第(i+1)个s1可匹配的s2中字符数量 + 除去x个完整周期后余下的部分可匹配的字符数量
                return (int) (res / s2.size() / n2);
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
