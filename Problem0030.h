//
// Created by Fengwei Zhang on 10/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0030_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0030_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 直接背诵，暴力枚举：https://www.acwing.com/solution/content/113/
    // https://www.acwing.com/video/1352/
    // 由于数组中每个单词长度都是相同的，故可以按照单词的长度 len 来将 s 划分为 len 种候选单词序列
    // 举例来看 barfoothefoobarman，根据单词长度为 3，可以得到 3 种不同的划分
    // 分别是 bar foo the foo bar man、arf oot hef oob arm an 和 rfo oth efo oba rma n 三种
    // 每个单词可多次出现，对于以上的每一种划分来说，仅需要用哈希表就可以暴力的算出来，能否能由单词列表中的所有单词拼接而成
public:
    vector<int> findSubstring(const string &s, const vector<string> &words) {
        if (words.empty()) {
            return {};
        }
        unordered_map<string, int> word_freq;
        for (const auto &item: words) {
            ++word_freq[item];
        }
        const int w = (int) words[0].size();
        const int m = (int) words.size();
        vector<int> res;
        unordered_map<string, int> window;
        for (int i = 0; i < w; ++i) {  // 枚举单词序列可能的起点位置
            int counter = 0;
            for (auto j = i; j + w <= (int) s.size(); j += w) {  // 滑动窗口，枚举新单词的起点
                if (j - m * w >= i) {  // 删除最早的单词
                    auto prev_w = s.substr(j - m * w, w);
                    --window[prev_w];
                    if (word_freq.count(prev_w) && window[prev_w] < word_freq[prev_w]) {
                        --counter;
                    }
                }
                auto seg = s.substr(j, w);
                ++window[seg];
                if (word_freq.count(seg) && window[seg] <= word_freq[seg]) {  // 词典中的单词出现
                    ++counter;
                }
                if (counter == m) {  // 匹配成功
                    res.emplace_back(j - (m - 1) * w);  // j在第(m-1)个单词的终点后面，j是第m个单词的起点
                }
            }
            window.clear();
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0030_H
