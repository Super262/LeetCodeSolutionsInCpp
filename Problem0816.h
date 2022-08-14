//
// Created by Fengwei Zhang on 3/31/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0816_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0816_H

#include <vector>
#include <string>

using namespace std;

class Problem0816 {
    // 枚举分界点i，将数字s分成2部分a、b，分别处理；对子字符串a，枚举小数点的位置，生成多种方案
    // 对于任意小数，末尾不能有0、整数部分不能有前导0；最后，组合a、b的任意2种方案，生成答案
public:
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.size() - 2);
        vector<string> ans;
        for (int i = 1; i < s.size(); ++i) {  // 枚举分割点
            auto a = generateNumbers(s.substr(0, i));
            if (a.empty()) {
                continue;
            }
            auto b = generateNumbers(s.substr(i));
            if (b.empty()) {
                continue;
            }
            for (const auto &x: a) {
                for (const auto &y: b) {
                    string temp = "(";
                    temp += x;
                    temp += ", ";
                    temp += y;
                    temp += ")";
                    ans.emplace_back(temp);
                }
            }
        }
        return ans;
    }

private:
    vector<string> generateNumbers(const string &s) {
        vector<string> ans;
        if (s.size() == 1 || s[0] != '0') {  // 不含小数点的情况
            ans.emplace_back(s);
        }
        for (int i = 1; i < s.size(); ++i) {  // 枚举小数点的位置
            if (s.back() == '0') {  // 浮点数末尾有多余的"0"，直接停止分割
                return ans;
            }
            if (i > 1 && s[0] == '0') {  // 有前导零，直接停止分割
                return ans;
            }
            ans.emplace_back(s.substr(0, i) + "." + s.substr(i));
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0816_H
