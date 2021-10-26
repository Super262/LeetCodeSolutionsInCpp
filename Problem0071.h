//
// Created by Fengwei Zhang on 10/26/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0071_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0071_H

#include <string>

using namespace std;

class Problem0071 {
public:
    string simplifyPath(string path) {
        if (path.back() != '/') {  // 添加终止符号
            path.push_back('/');
        }
        string res
        string name;
        for (auto ch: path) {
            if (ch != '/') {
                name.push_back(ch);
            } else {
                if (name == "..") {
                    while (!res.empty() && res.back() != '/') {  // 弹出路径名
                        res.pop_back();
                    }
                    if (!res.empty()) {  // 弹出终止符
                        res.pop_back();
                    }
                } else if (!name.empty() && name != ".") {
                    res.push_back('/');
                    res.append(name);
                }
                name.clear(); // 重新记录路径名
            }
        }
        if (res.empty()) {
            res = "/";
        }
        return res;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0071_H
