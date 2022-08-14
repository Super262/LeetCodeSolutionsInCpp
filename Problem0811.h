//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0811_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0811_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Problem0811 {
    // 哈希表；对每个域名，记录其所有有效后缀出现的次数；注意：输出答案时，要将后缀反序
public:
    vector<string> subdomainVisits(const vector<string> &cps) {
        unordered_map<string, int> counter;
        for (const auto &cp: cps) {
            int i = 0;
            int freq = 0;  // 获取频率
            while (i < (int) cp.size() && cp[i] != ' ') {
                freq = freq * 10 + (cp[i] - '0');
                ++i;
            }
            i = (int) cp.size() - 1;
            string s;  // 获取后缀
            while (i >= 0) {
                if (cp[i] == '.') {
                    if (!s.empty()) {
                        counter[s] += freq;
                    }
                } else if (cp[i] == ' ') {
                    if (!s.empty()) {
                        counter[s] += freq;
                    }
                    break;
                }
                s += cp[i];
                --i;
            }
        }
        vector<string> ans;
        ans.reserve(counter.size());
        for (const auto &item: counter) {
            const auto &s = string(item.first.rbegin(), item.first.rend());
            ans.emplace_back(to_string(item.second) + " " + s);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0811_H
