//
// Created by Fengwei Zhang on 11/27/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0420_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0420_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    // https://www.acwing.com/solution/content/25738/
public:
    struct cmp {
        bool operator()(int a, int b) {
            if (a % 3 == 0) {
                return false;
            }
            if (b % 3 == 0) {
                return true;
            }
            if (a % 3 == 1) {
                return false;
            }
            if (b % 3 == 1) {
                return true;
            }
            return false;
        }
    };

    int strongPasswordChecker(string s) {
        auto n = (int) s.size();
        bool cap = false, low = false, num = false;
        // 统计以s[i]结尾的相同字符的子串长度 以及特殊字符的出现情况
        vector<int> length(n);
        for (int i = 0, j = 0; i < n; i++) {
            char ch = s[i];
            if (isupper(ch)) {
                cap = true;
            } else if (islower(ch)) {
                low = true;
            } else if (isdigit(ch)) {
                num = true;
            }
            int len = 1;
            while (j < n && s[i] == s[j]) {
                length[j] = len++;
                j++;
            }
            i = j - 1;
        }
        if (n < 6) {
            return max(6 - n, 3 - cap - low - num);
        }
        priority_queue<int, vector<int>, cmp> pq;
        int i = n - 1;
        while (i >= 0) {
            if (length[i] >= 3) {
                pq.push(length[i]);
            }
            i -= length[i];
        }
        int op = 0, tot = num + cap + low;
        if (n > 20) {
            while (n > 20 && !pq.empty()) {
                int x = pq.top();
                pq.pop();
                op++;
                x--;
                n--;
                if (x >= 3) {
                    pq.push(x);
                }
            }
            if (pq.empty()) {
                return op + n - 20 + (3 - tot);
            }
        }
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            int t = x / 3;
            op += t;
            tot += t;
        }
        return op + max(0, 3 - tot);
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0420_H
