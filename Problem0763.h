//
// Created by Fengwei Zhang on 2/26/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0763_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0763_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Problem0763 {
    // 用哈希表记录每种字符的最后出现位置，以确定每个分段的结尾位置
public:
    vector<int> partitionLabels(const string &s) {
        unordered_map<char, int> last_idx;
        for (int i = 0; i < (int) s.size(); ++i) {
            last_idx[s[i]] = i;
        }
        vector<int> ans;
        int st = 0;
        int ed = -1;
        for (int i = 0; i < (int) s.size(); ++i) {
            ed = max(last_idx[s[i]], ed);
            if (i == ed) {
                ans.emplace_back(ed - st + 1);
                ed = i + 1;
                st = i + 1;
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0763_H
