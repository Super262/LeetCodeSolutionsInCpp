//
// Created by Fengwei Zhang on 10/13/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2223_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2223_H

#include <string>

using namespace std;

class Problem2223 {
    // Z Algorithm: https://oi-wiki.org/string/z-func/
public:
    long long sumScores(const string &s) {
        const auto n = (int) s.size();
        int z_list[n];
        memset(z_list, 0, sizeof z_list);
        zFunc(s, n, z_list);
        long long ans = n;
        for (const auto &x: z_list) {
            ans += x;
        }
        return ans;
    }

private:
    void zFunc(const string &s, const int n, int *z) {
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r && z[i - l] < r - i + 1) {
                z[i] = z[i - l];
            } else {
                z[i] = max(0, r - i + 1);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                    ++z[i];
                }
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM2223_H
