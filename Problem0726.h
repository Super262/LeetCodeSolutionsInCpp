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
#include <unordered_map>

using namespace std;

class Problem0726 {
    // DFS，哈希表存储元素个数；遇到"("，开始下层递归'；遇到")"，结束本层递归；最后，用map存储元素，获得有序排列
public:
    string countOfAtoms(const string &formula) {
        int ch_idx = 0;
        auto ele_cnt = dfs(formula, ch_idx);
        string ans;
        map<string, int> ele_cnt_sorted = {ele_cnt.begin(), ele_cnt.end()};
        for (const auto &item: ele_cnt_sorted) {
            ans += item.first;
            if (item.second > 1) {
                ans += to_string(item.second);
            }
        }
        return ans;
    }

private:
    unordered_map<string, int> dfs(const string &formula, int &ch_idx) {  // 不要忘记：ch_idx是引用
        unordered_map<string, int> counter;
        while (ch_idx < (int) formula.size()) {
            if (formula[ch_idx] == ')') {  // 递归的结束条件
                return counter;
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
                    counter[item.first] += item.second * factor;
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
                counter[key] += factor;
            }
        }
        return counter;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0726_H
