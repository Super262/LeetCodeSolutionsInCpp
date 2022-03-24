
//
// Created by Fengwei Zhang on 2/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0753_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0753_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    // 欧拉回路，必须掌握：https://www.acwing.com/solution/content/50358/
public:
    string crackSafe(int n, int k) {
        m = 1;
        for (int i = 1; i <= n; ++i) {
            m *= k;
        }
        seen.resize(m, false);
        solve(0, k);
        auto ans = res + string(n - 1, '0');
        reverse(ans.begin(), ans.end());  // 这里不翻转其实也可以通过，但翻转才是刚才遍历得到的欧拉回路。
        return ans;
    }

private:
    vector<bool> seen;
    stack<int> st;
    string res;
    int m;

    void solve(int u, int k) {
        for (int c = 0; c < k; c++) {
            int e = u + c;
            if (seen[e]) {
                continue;
            }
            seen[e] = true;
            st.emplace(c);
            auto v = e * k % m;
            solve(v, k);
            res.push_back((char) (st.top() + '0'));
            st.pop();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0753_H
