
//
// Created by Fengwei Zhang on 5/17/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0271_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0271_H

#include <vector>
#include <string>

using namespace std;

class Codec {
    // 将每个字符串的长度信息保存在首部（3个字符，每个保存10进制数），构成编码字符串：len(a) + a + len(b) + b + ...
public:

    // Encodes a list of strings to a single string.
    string encode(const vector<string> &strs) {
        string ans;
        for (const auto &s: strs) {
            ans += intToStr((int) s.size()) + s;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(const string &s) {
        vector<string> ans;
        for (int i = 0; i < (int) s.size(); ++i) {
            auto x = strToInt(s.substr(i, K));
            ans.emplace_back(s.substr(i + K, x));
            i += K + x - 1;
        }
        return ans;
    }

private:
    const int K = 3;
    const int M = 10;

    string intToStr(int x) {  // 整数转长度为K的字符串（20 -> "020"）
        string s;
        while (x) {
            s += (char) ('0' + x % M);
            x /= M;
        }
        if (s.size() < K) {
            s += string(K - s.size(), '0');
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int strToInt(const string &s) {  // 长度为K的字符串转整数（"020" -> 20）
        int x = 0;
        for (const auto &ch: s) {
            x *= M;
            x += ch - '0';
        }
        return x;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0271_H
