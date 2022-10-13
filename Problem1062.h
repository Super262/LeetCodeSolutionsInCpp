//
// Created by Fengwei Zhang on 10/13/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1062_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1062_H

#include <string>
#include <cstring>

using namespace std;

class Problem1062 {
public:
    int longestRepeatingSubstring(const string &s) {
        const auto n = (int) s.size();
        const auto str = " " + s;
        getSA(str, n, 'z');
        getHeightAndRank(str, n);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (height[i] > ans) {
                ans = height[i];
            }
        }
        return ans;
    }

private:
    static const int N = 1500;
    int x[2 * N + 10];
    int y[2 * N + 10];
    int cnt[2 * N + 10];
    int sa[2 * N + 10];
    int rank[2 * N + 10];
    int height[2 * N + 10];

    void getSA(const string &str, int n, int m) {
        for (int i = 1; i <= n; ++i) {
            x[i] = (unsigned char) str[i];
            ++cnt[x[i]];
        }
        for (int i = 2; i <= m; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (auto i = n; i >= 0; --i) {
            sa[cnt[x[i]]] = i;
            --cnt[x[i]];
        }
        for (int k = 1; k <= n; k *= 2) {
            int num = 0;
            for (auto i = n - k + 1; i <= n; ++i) {
                ++num;
                y[num] = i;
            }
            for (int i = 1; i <= n; ++i) {
                if (sa[i] > k) {
                    ++num;
                    y[num] = sa[i] - k;
                }
            }
            memset(cnt, 0, sizeof cnt);
            for (int i = 1; i <= n; ++i) {
                ++cnt[x[i]];
            }
            for (int i = 2; i <= m; ++i) {
                cnt[i] += cnt[i - 1];
            }
            for (auto i = n; i > 0; --i) {
                sa[cnt[x[y[i]]]] = y[i];
                --cnt[x[y[i]]];
                y[i] = 0;
            }
            swap(x, y);
            x[sa[1]] = 1;
            num = 1;
            for (int i = 2; i <= n; ++i) {
                bool dup = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k];
                if (!dup) {
                    ++num;
                }
                x[sa[i]] = num;
            }
            if (num == n) {
                break;
            }
            m = num;
        }
    }

    void getHeightAndRank(const string &str, int n) {
        for (int i = 1; i <= n; ++i) {
            rank[sa[i]] = i;
        }
        for (int i = 1, k = 0; i <= n; ++i) {
            if (rank[i] == 1) {
                continue;
            }
            if (k) {
                --k;
            }
            auto j = sa[rank[i] - 1];
            while (i + k <= n && str[i + k] == str[j + k]) {
                ++k;
            }
            height[rank[i]] = k;
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1062_H
