//
// Created by Fengwei Zhang on 5/28/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0411_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0411_H

#include <string>
#include <vector>

using namespace std;

class Solution {
    // 若2个字符串长度不相等，那么它们不会存在相同的缩写；若dict中所有字符串的长度都不等于target的长度，答案就是to_string(target.size());
    // 对于任意2个缩写a、b，若它们存在1个不同的字符，它们是不同的；首先，我们取出dict中每个和target长度相同的字符串x，执行"target XOR x"
    // 举例：若target="apple"、x="blade"，"target XOR x"=30（"11110"）；我们用数组xor_res存储所有上述异或操作的结果
    // 设target长度为m，其有效缩写共有2^m个；我们用二进制数a代表target的缩写：若字符target[i]未被缩写，则a[i]=1；若target[i]被缩写，则a[i]=0
    // 若a（target的缩写）和xor_res中所有数字做"AND"运算的结果不为0，那么a是有效的，说明a代表的缩写和dict中任意字符串的缩写都不相同
    // 因此，我们要找到长度最小的a，并返回a对应的缩写字符串
public:
    string minAbbreviation(const string &target, const vector<string> &dict) {
        const auto n = (int) target.size();
        vector<int> xor_res;
        for (const auto &x: dict) {
            if (x.size() != target.size()) {  // 长度不同，不可能存在相同的缩写，直接跳过
                continue;
            }
            xor_res.emplace_back(strXOR(target, x, n));
        }
        if (xor_res.empty()) {  // 没有长度和target相同的字符串，返回"全缩写"（target的长度）
            return to_string(target.size());
        }
        const int max_s = (1 << n) - 1;
        int min_len = n;
        int ans_abbr = max_s;
        for (int a = 1; a <= max_s; ++a) {  // 遍历，尝试所有可能的缩写
            bool is_valid = true;
            for (const auto &b: xor_res) {
                if (!(a & b)) {
                    is_valid = false;
                    break;
                }
            }
            if (!is_valid) {
                continue;
            }
            auto cur_len = abbrLength(a, n);
            if (cur_len < min_len) {
                min_len = cur_len;
                ans_abbr = a;
            }
        }
        return abbrToStr(target, ans_abbr, n);
    }

private:
    int strXOR(const string &a, const string &b, int n) {  // 字符串按位异或
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            ans <<= 1;
            if (a[i] != b[i]) {
                ans += 1;
            }
        }
        return ans;
    }

    int abbrLength(int s, int n) {  // 计算缩写（二进制数）的长度，每段连续的"0"的长度为1，每个"1"的长度为1
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s & 1) {
                ++ans;
                s >>= 1;
                continue;
            }
            auto j = i;
            while (j < n) {
                if (s & 1) {
                    break;
                }
                s >>= 1;
                ++j;
            }
            ++ans;
            i = j - 1;
        }
        return ans;
    }

    string abbrToStr(const string &s, int abbr, int n) {  // 根据二进制数和原字符串生成缩写后的字符串
        string ans;
        ans.reserve(s.size());
        for (int i = 0; i < n; ++i) {
            if (abbr & 1) {
                ans += s[n - i - 1];
                abbr >>= 1;
                continue;
            }
            auto j = i;
            while (j < n) {
                if (abbr & 1) {
                    break;
                }
                abbr >>= 1;
                ++j;
            }
            auto t = to_string(j - i);
            reverse(t.begin(), t.end());
            ans += t;
            i = j - 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0411_H
