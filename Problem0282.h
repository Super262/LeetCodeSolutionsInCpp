//
// Created by Fengwei Zhang on 11/16/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0282_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0282_H

#include <vector>
#include <string>

using namespace std;

class Solution {
    // 巧妙的常数优化：我们维护不变式a+b*()，括号中的数是我们当前枚举的数字
    // 若下个运算符是"+"，那么 a+b*(c)+()=(a+b*c)+1*()
    // 若下个运算符是"-"，那么 a+b*(c)-()=(a+b*c)+(-1)*()
    // 若下个运算符是"+"，那么 a+b*(c)*()=a+(b*c)*()
    // 最终等式为a+1*()，a即是最终结果
    // https://www.acwing.com/solution/content/332/
    // 细节：DFS后要注意恢复现场，撤销当前阶段所有操作，要反复检查撤退的步数，确保正确
public:
    vector<string> addOperators(const string &num, int target) {
        vector<string> ans;
        string path;
        dfs(num, 0, 0, 1, target, path, ans);
        return ans;
    }

private:
    void dfs(const string &num, int u, long long a, long long b, int target, string &path, vector<string> &ans) {
        if (u >= (int) num.size()) {
            if (a == target) {
                ans.emplace_back(path);
                ans.back().pop_back();  // 弹出末尾的'+'
            }
            return;
        }
        long long c = 0;
        for (auto i = u; i < (int) num.size(); ++i) {
            c = c * 10 + (num[i] - '0');
            path += num[i];
            path += '+';
            dfs(num, i + 1, a + b * c, 1, target, path, ans);
            path.pop_back();
            if (i + 1 < (int) num.size()) {
                path += '-';
                dfs(num, i + 1, a + b * c, -1, target, path, ans);
                path.pop_back();
                path += '*';
                dfs(num, i + 1, a, b * c, target, path, ans);
                path.pop_back();
            }
            if (num[u] == '0') {  // 发现前导零，终止
                path.pop_back();  // 弹出'0'
                return;
            }
        }
        for (auto i = u; i < (int) num.size(); ++i) {  // 弹出当前末尾的数字
            path.pop_back();
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0282_H
