//
// Created by Fengwei Zhang on 1/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0535_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0535_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 生成K位62进制数
public:
    // Encodes a URL to a shortened URL.
    string encode(const string &long_url) {
        while (true) {
            auto short_url = random_str(6);
            if (!short_to_long.count(short_url)) {
                short_to_long[short_url] = long_url;
                return "http://tinyurl.com/" + short_url;
            }
        }
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(const string &short_url) {
        return short_to_long[short_url.substr(19)];
    }

private:
    const string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> short_to_long;

    string random_str(int k) {
        string res(k, '\0');
        for (int i = 0; i < k; ++i) {
            res[i] = chars[random() % chars.size()];
        }
        return res;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0535_H
