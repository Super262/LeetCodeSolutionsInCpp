//
// Created by Fengwei Zhang on 12/9/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0767_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0767_H

#include <string>
#include <unordered_map>

using namespace std;

class Problem0767 {
    // 构造n/2个抽屉，每个抽屉包含2个不同字符：注意特判，将频率大于n/2的字符放在偶数位置，因为n/2等于奇数位的数量
public:
    string reorganizeString(const string &s) {
        const int n = (int) s.size();
        unordered_map<char, int> counter;
        for (const auto &ch: s) {
            counter[ch]++;
            if (counter[ch] > (n + 1) / 2) {  // 相同字符会相邻，无解
                return "";
            }
        }
        string ans(s.size(), '\0');
        int i = 1;  // 先奇数位，再偶数位
        int j = 0;
        for (const auto &item: counter) {
            auto ch = item.first;
            if (item.second == 0) {
                continue;
            }
            if (counter[ch] <= n / 2) {  // 放在奇数位
                while (counter[ch] && i < n) {
                    ans[i] = ch;
                    counter[ch]--;
                    i += 2;
                }
            }
            while (counter[ch] && j < n) {  // 放在偶数位
                ans[j] = ch;
                counter[ch]--;
                j += 2;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0767_H
