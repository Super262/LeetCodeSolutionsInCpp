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

class Problem0726 {
    // map存储时，key是有序的
private:
    map<string, int> dfs(const string &formula, int &chIdx) {
        map<string, int> result;
        while (chIdx < (int) formula.size()) {
            if (formula[chIdx] == ')') {  // 递归的结束条件
                break;
            }
            if (formula[chIdx] == '(') {  // 子方程式，递归
                ++chIdx;  // 跳过左括号
                auto eleCnt = dfs(formula, chIdx);
                ++chIdx;  // 跳过右括号
                // 检测系数是否存在
                auto i = chIdx;
                while (i < (int) formula.size() && isdigit(formula[i])) {
                    ++i;
                }
                int factor = 1;
                if (i > chIdx) {
                    factor = stoi(formula.substr(chIdx, i - chIdx));
                    chIdx = i;
                }
                for (auto &item: eleCnt) {
                    result[item.first] += item.second * factor;
                }
            } else {
                auto i = chIdx + 1; // 跳过大写字母
                while (i < (int) formula.size() && formula[i] >= 'a' && formula[i] <= 'z') {
                    ++i;
                }
                auto key = formula.substr(chIdx, i - chIdx);
                chIdx = i;
                int factor = 1;
                while (i < (int) formula.size() && isdigit(formula[i])) {
                    ++i;
                }
                if (i > chIdx) {
                    factor = stoi(formula.substr(chIdx, i - chIdx));
                    chIdx = i;
                }
                result[key] += factor;
            }
        }
        return result;
    }

    string countOfAtoms(const string &formula) {
        auto eleCnt = dfs(formula, 0);
        string result;
        for (auto &item: eleCnt) {
            result += item.first;
            if (item.second > 1) {
                result += to_string(item.second);
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0726_H
