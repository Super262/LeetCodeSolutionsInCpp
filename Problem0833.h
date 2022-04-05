//
// Created by Fengwei Zhang on 4/5/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0833_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0833_H

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
    // 若从左到右处理s，替换靠左的区间r1会改变靠右的区间r2的索引；因此，我们选择从右向左处理s，r2不会影响r1
public:
    string findReplaceString(const string &s,
                             const vector<int> &indices,
                             const vector<string> &sources,
                             const vector<string> &targets) {
        const auto m = (int) indices.size();
        int id[m];
        for (int i = 0; i < m; ++i) {
            id[i] = i;
        }
        sort(id, id + m, [&](const int &a, const int &b) {
            return indices[a] < indices[b];
        });
        auto ans = s;
        for (auto i = m - 1; i >= 0; --i) {
            auto j = id[i];
            if (!isSame(s, indices[j], sources[j])) {
                continue;
            }
            ans = ans.substr(0, indices[j]) + targets[j] + ans.substr(indices[j] + sources[j].size());
        }
        return ans;
    }

private:
    static bool isSame(const string &s, int st, const string &t) {  // 判断s[st:st+len(t)-1]是否等于t
        if (st + t.size() - 1 >= s.size()) {
            return false;
        }
        for (auto i = st; i < st + t.size(); ++i) {
            if (s[i] != t[i - st]) {
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0833_H
