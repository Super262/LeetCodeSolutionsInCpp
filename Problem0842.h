//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0842_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0842_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 由斐波那契数列数列的递推公式可知：我们只需确定前2个数a、b，再根据公式验证后面的部分即可
public:
    vector<int> splitIntoFibonacci(const string &s) {
        // 每个数字x最多为10位且len(x) <= len(s)/3
        for (int al = 1; al <= 10 && al <= (s.size() + 2) / 3; ++al) {  // 枚举第1个数a的长度al
            if (al > 1 && s[0] == '0') {  // 排除前导0
                break;
            }
            auto a = stoll(s.substr(0, al));
            for (int bl = 1; bl <= 10 && bl <= (s.size() + 2) / 3 && al + bl <= s.size(); ++bl) {  // 枚举第2个数b的长度bl
                if (bl > 1 && s[al] == '0') {  // 排除前导0
                    break;
                }
                auto b = stoll(s.substr(al, bl));
                auto res = getSeq(a, b, s, al + bl);
                if (res.size() >= 3) {  // 序列有效，直接返回
                    return res;
                }
            }
        }
        return {};
    }

private:
    vector<int> getSeq(long long a, long long b, const string &s, int cs_st) {  // cs_st是第3个数的起始索引
        vector<int> ans = {(int) a, (int) b};
        while (cs_st < s.size()) {
            auto c = a + b;
            if (a > INT_MAX || b > INT_MAX || c > INT_MAX) {  // 数值超限
                return {};
            }
            auto cs = to_string(c);
            if (!isSame(s, cs_st, cs)) {  // c未出现
                return {};
            }
            ans.emplace_back((int) c);  // 保存c
            a = b;
            b = c;
            cs_st += (int) cs.size();  // 继续递推
        }
        return ans;
    }

    bool isSame(const string &a, int st, const string &b) {
        if (b.size() + st - 1 >= a.size()) {
            return false;
        }
        auto i = st;
        int j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] != b[j]) {
                return false;
            }
            ++i;
            ++j;
        }
        return j == b.size();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0842_H
