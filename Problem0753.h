
//
// Created by Fengwei Zhang on 2/25/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0753_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0753_H

#include <string>
#include <unordered_set>

using namespace std;

class Problem0753 {
    // Hierholzer算法求欧拉回路，必须掌握：https://www.jianshu.com/p/8394b8e5b878
public:
    string crackSafe(int n, int k) {
        if (n == 1 && k == 1) {
            return "0";
        }
        unordered_set<string> visited;
        auto st = string(n - 1, '0');
        string res;
        findEuler(st, k, visited, res);
        res.append(st);
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void findEuler(const string &cur, const int k, unordered_set<string> &visited, string &res) {
        for (int i = 0; i < k; ++i) {
            auto next = cur + to_string(i);
            if (visited.count(next)) {
                continue;
            }
            visited.insert(next);
            findEuler(next.substr(1), k, visited, res);
            res.append(to_string(i));
        }
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0753_H
