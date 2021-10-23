//
// Created by Fengwei Zhang on 10/23/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0014_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0014_H

class Problem0014 {
public:
    string longestCommonPrefix(const vector <string> &strs) {
        if (strs.empty()) {
            return "";
        }
        string res;
        for (int i = 0; true; ++i) {
            char ch = '\0';
            for (const auto &s: strs) {
                if (i >= s.size()) {
                    return res;
                }
                if (ch == '\0') {
                    ch = s[i];
                }
                if (ch != s[i]) {
                    return res;
                }
            }
            res.push_back(ch);
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0014_H
