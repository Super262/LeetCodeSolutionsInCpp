//
// Created by Fengwei Zhang on 7/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0751_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0751_H

#include <vector>
#include <string>

using namespace std;

class Problem0751 {
    // 贪心算法：对当前IP和n，我们尝试使用最长的子网掩码；我们比较lowBit(ip)和n的二进制长度，得到最大值x，那么mask=33-x；再更新当前IP，继续尝试
    // 为了简化计算，我们会先将IP转化为1个256进制数字；特殊情况：IP为"0.0.0.0"时，mask只与n相关
public:
    vector<string> ipToCIDR(const string &ip, int n) {
        auto start = ipToInteger(ip);
        vector<string> ans;
        while (n > 0) {
            int mask;
            if (start) {
                mask = max(33 - bitLength(start & -start), 33 - bitLength(n));
            } else {
                mask = 33 - bitLength(n);
            }
            ans.emplace_back(integerToIp(start) + '/' + to_string(mask));
            int t = 1 << (32 - mask);
            start += t;
            n -= t;
        }
        return ans;
    }

private:
    int bitLength(unsigned long long x) {  // 求数字x的二进制长度
        if (!x) {
            return 1;
        }
        int cnt = 0;
        while (x) {
            x >>= 1;
            ++cnt;
        }
        return cnt;
    }

    unsigned long long ipToInteger(const string &s) {  // 转化IP地址为256进制数字
        unsigned long long num = 0;
        int l = 0;
        while (l < (int) s.size()) {
            auto r = l;
            unsigned long long x = 0;
            while (r < (int) s.size() && s[r] != '.') {
                x = x * 10 + (s[r] - '0');
                ++r;
            }
            num = num * 256 + x;
            l = r + 1;
        }
        return num;
    }

    string integerToIp(unsigned long long x) {  // 转化256进制数字为IP地址
        string s;
        unsigned long long b = 256 * 256 * 256;
        while (b) {
            auto y = x / b;
            s += to_string(y) + '.';
            x %= b;
            b /= 256;
        }
        s.pop_back();
        return s;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0751_H
