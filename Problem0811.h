//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0811_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0811_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    // 对每个域名，记录其所有有效后缀出现的次数
public:
    vector<string> subdomainVisits(const vector<string> &cps) {
        unordered_map<string, int> counter;
        for (const auto &cp: cps) {
            auto k = cp.find_first_of(' ');
            auto f = stoi(cp.substr(0, k));
            auto s = cp.substr(k + 1);
            while (true) {
                counter[s] += f;
                k = s.find_first_of('.');
                if (k == string::npos) {
                    break;
                }
                s = s.substr(k + 1);
            }
        }
        vector<string> ans;
        ans.reserve(counter.size());
        for (const auto &item: counter) {
            ans.emplace_back(to_string(item.second) + " " + item.first);
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0811_H
