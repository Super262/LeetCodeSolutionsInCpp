//
// Created by Fengwei Zhang on 2/23/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0736_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0736_H

#include <string>
#include <unordered_map>

using namespace std;

class Problem0736 {
    // 经典算法，直接背诵
public:
    int evaluate(const string &expression) {
        int k = 0;
        return dfs(expression, k, unordered_map<string, int>());
    }

private:
    int dfs(const string &str, int &k, unordered_map<string, int> vars) {
        int value = 0;
        k++;  // 跳过 '('
        auto type = str.substr(k, 3);
        if (type == "let") {
            k += 4;  // 跳过 "let "
            while (str[k] != ')') {
                if (str[k] == '(' || str[k] == '-' || isdigit(str[k])) {  // 子表达式，递归处理
                    value = getValue(str, k, vars);
                    break;
                }
                string name;  // 获得变量名
                while (str[k] != ' ' && str[k] != ')') {
                    name += str[k];
                    ++k;
                }
                if (str[k] == ')') {
                    value = vars[name];
                    break;
                }
                k++;  // 跳过 ' '
                vars[name] = getValue(str, k, vars);
                k++;  // 跳过 ' '
            }
        } else if (type == "add") {
            k += 4;  // 跳过 "add "
            auto a = getValue(str, k, vars);
            k++;  // 跳过 ' '
            auto b = getValue(str, k, vars);
            value = a + b;
        } else {
            k += 5;  // 跳过 "mult "
            auto a = getValue(str, k, vars);
            k++;  // 跳过 ' '
            auto b = getValue(str, k, vars);
            value = a * b;
        }
        k++;  // 跳过 ')'
        return value;
    }

    int getValue(const string &str, int &k, unordered_map<string, int> &vars) {
        int value;
        if (str[k] == '-' || isdigit(str[k])) {
            auto i = k + 1;
            while (isdigit(str[i])) {
                ++i;
            }
            value = stoi(str.substr(k, i - k));
            k = i;
        } else if (str[k] != '(') {
            string name;
            while (str[k] != ' ' && str[k] != ')') {
                name += str[k];
                ++k;
            }
            value = vars[name];
        } else {
            value = dfs(str, k, vars);
        }
        return value;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0736_H
