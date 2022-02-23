//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0726_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0726_H

#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <map>

using namespace std;

class Solution {
    // map存储时，key是有序的
public:
    string countOfAtoms(const string &formula) {
        int ch_idx = 0;
        auto ele_cnt = dfs(formula, ch_idx);
        string result;
        for (auto &item: ele_cnt) {
            result += item.first;
            if (item.second > 1) {
                result += to_string(item.second);
            }
        }
        return result;
    }

private:
    map<string, int> dfs(const string &formula, int &ch_idx) {  // 不要忘记：chIdx是引用
        map<string, int> result;
        while (ch_idx < (int) formula.size()) {
            if (formula[ch_idx] == ')') {  // 递归的结束条件
                break;
            }
            if (formula[ch_idx] == '(') {  // 子方程式，递归
                ++ch_idx;  // 跳过左括号
                auto ele_cnt = dfs(formula, ch_idx);
                ++ch_idx;  // 跳过右括号
                // 检测系数是否存在
                auto i = ch_idx;
                while (i < (int) formula.size() && isdigit(formula[i])) {
                    ++i;
                }
                int factor = 1;
                if (i > ch_idx) {
                    factor = stoi(formula.substr(ch_idx, i - ch_idx));
                    ch_idx = i;
                }
                for (auto &item: ele_cnt) {
                    result[item.first] += item.second * factor;
                }
            } else {
                auto i = ch_idx + 1; // 跳过大写字母
                while (i < (int) formula.size() && formula[i] >= 'a' && formula[i] <= 'z') {
                    ++i;
                }
                auto key = formula.substr(ch_idx, i - ch_idx);
                ch_idx = i;
                int factor = 1;
                while (i < (int) formula.size() && isdigit(formula[i])) {
                    ++i;
                }
                if (i > ch_idx) {
                    factor = stoi(formula.substr(ch_idx, i - ch_idx));
                    ch_idx = i;
                }
                result[key] += factor;
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0726_H
