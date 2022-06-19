//
// Created by Fengwei Zhang on 6/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0555_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0555_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 观察问题的性质，可以发现，如果一个字符串的内部没有被作为循环的起点，那么可以直接确定它是否需要反转
    // 这点很好证明：若字符串s的字典序大于其反转字符串s'，对于任意包含s的字符串S，将其中的s替换为s'后得到S'，S'>S一定成立
    // 因此，我们可以通过预处理，确定每个字符串s和它的反序s'的大小关系；再枚举包含循环起点的字符串strs[i]（0<=i<=n-1），获得答案
    // 对于包含循环起点的字符串strs[i]，设循环起点为j（设m=strs[i].size()，0<=j<=m-1），设cur为当前的分割字符串
    // cur=strs[i][j+1:m-1]+sum(max(strs/rev_strs)[i+1:n-1])+strs[i][0:j]，或者
    // cur=rev_strs[i][j+1:m-1]+sum(max(strs/rev_strs)[i+1:n-1])+rev_strs[i][0:j]，取较大的作为答案
public:
    string splitLoopedString(vector<string> &strs) {
        const auto n = (int) strs.size();
        string rev_strs[n];  // rev_strs[i]是strs[i]的反序
        bool rev_is_larger[n];  // rev_is_larger[i]=rev_strs[i]>strs[i]
        for (int i = 0; i < n; ++i) {
            rev_strs[i] = string(strs[i].rbegin(), strs[i].rend());
            rev_is_larger[i] = rev_strs[i] > strs[i];
        }
        string ans;
        for (int i = 0; i < n; ++i) {  // 枚举包含循环起点的字符串
            string cur;
            for (auto j = i + 1; j < n; ++j) {
                if (rev_is_larger[j]) {
                    cur += rev_strs[j];
                } else {
                    cur += strs[j];
                }
            }
            for (int j = 0; j < i; ++j) {
                if (rev_is_larger[j]) {
                    cur += rev_strs[j];
                } else {
                    cur += strs[j];
                }
            }
            // 枚举循环起点
            for (int j = 1; j <= (int) strs[i].size(); ++j) {
                const auto &s = strs[i];
                ans = max(ans, s.substr(j) + cur + s.substr(0, j));
            }
            for (int j = 1; j <= (int) rev_strs[i].size(); ++j) {
                const auto &s = rev_strs[i];
                ans = max(ans, s.substr(j) + cur + s.substr(0, j));
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0555_H
