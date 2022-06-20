//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0567_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0567_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 双指针经典题目，注意细节：我们要在s2中找到1个区间s2[l:r]，s2[l:r]的长度和s1相等、字符频率相等
public:
    bool checkInclusion(const string &s1, const string &s2) {
        unordered_map<char, int> f1;
        unordered_map<char, int> f2;
        for (const auto &ch: s1) {
            ++f1[ch];
        }
        // 注意：在修改f2[ch]前后，都要检查匹配情况！！
        for (int l = 0, r = 0, counter = 0; r < (int) s2.size(); ++r) {
            if (checkFreq(s2[r], f1, f2)) {  // 修改前，字符频率相等
                --counter;
            }
            ++f2[s2[r]];
            if (checkFreq(s2[r], f1, f2)) {  // 修改后，字符频率相等
                ++counter;
            }
            if (r - l + 1 > (int) s1.size()) {  // 这里不必用while，因为l、r每次只会移动1步
                if (checkFreq(s2[l], f1, f2)) {
                    --counter;
                }
                --f2[s2[l]];
                if (checkFreq(s2[l], f1, f2)) {
                    ++counter;
                }
                ++l;
            }
            if (counter == (int) f1.size()) {
                return true;
            }
        }
        return false;
    }

private:
    bool checkFreq(char ch, const unordered_map<char, int> &s1, const unordered_map<char, int> &s2) {
        if (s1.count(ch) && s2.count(ch) && s1.find(ch)->second == s2.find(ch)->second) {
            return true;
        }
        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0567_H
