//
// Created by Fengwei Zhang on 4/15/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0936_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0936_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 1.贪心算法：设[i:j]为target的一个子字符串，若stamp == target[i:j]，表示我们对[i:j]的操作可以在最后一步完成；我们可以从结果反推操作序列
    // 2.拓扑排序：
    //   入度： 每个窗口字符串不匹配的数量，一旦是0，就完全匹配
    //   边： 不匹配的字符就加一个窗口的编号，一旦这个字符匹配后，对应窗口的入度就可以减1
public:
    vector<int> movesToStamp(const string &stamp, string target) {
        vector<int> res;
        while (true) {
            bool no_matched = true;
            for (int i = 0; i < (int) target.size(); ++i) {
                if (!isMatched(target, i, stamp)) {
                    continue;
                }
                res.emplace_back(i);
                no_matched = false;
                for (int j = 0; j < (int) stamp.size(); ++j) {
                    target[i + j] = '?';
                }
            }
            if (no_matched) {
                break;
            }
        }
        reverse(res.begin(), res.end());
        for (const auto &x: target) {
            if (x != '?') {
                return {};
            }
        }
        return res;
    }

private:
    bool isMatched(const string &s, int st, const string &t) {
        int space_cnt = 0;
        for (int i = 0; i < (int) t.size(); ++i) {
            if (s[st + i] == t[i]) {
                continue;
            }
            if (s[st + i] != '?') {
                return false;
            }
            ++space_cnt;
        }
        return space_cnt != (int) t.size();  // s不能只包含"?"
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0936_H
