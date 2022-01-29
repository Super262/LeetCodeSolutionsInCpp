//
// Created by Fengwei Zhang on 1/29/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0591_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0591_H

#include <string>
#include <stack>

using namespace std;

class Solution {
    // 模拟题，注意细节
public:
    bool isValid(const string &code) {
        stack<string> stk;
        for (int i = 0; i < code.size(); i++) {
            if (code[i] == '<' && code.substr(i, 9) != "<![CDATA[") {  // 标签
                int j = i + 1;
                string tag_name;
                bool is_end = false;
                while (j < code.size() && code[j] != '>') {
                    char c = code[j++];
                    if (c == '/' && j == i + 2) {  // 结束标签
                        is_end = true;
                        continue;
                    }
                    if (c < 'A' || c > 'Z') {
                        return false;  // 标签中有非大写英文字母
                    }
                    tag_name += c;
                }
                if (j == code.size()) {
                    return false;  // 标签没有以">"结束
                }
                if (tag_name.empty() || tag_name.size() > 9) {
                    return false;  // 标签名长度不在1~9之间
                }
                if (is_end) {
                    if (stk.empty() || stk.top() != tag_name) {
                        return false;  // 结束标签没有匹配
                    }
                    stk.pop();
                } else {
                    if (i && stk.empty()) {
                        return false;  // 至少有两组标签
                    }
                    stk.emplace(tag_name);
                }
                i = j;
            } else {  // 处理tag_content
                if (stk.empty()) {
                    return false;  // tag_content 不在标签内
                }
                if (code.substr(i, 9) == "<![CDATA[") {  // 处理CDATA
                    int j = i;
                    while (j < code.size() && code.substr(j, 3) != "]]>") {
                        ++j;
                    }
                    if (j == code.size()) {
                        return false;  // CDATA没有结尾
                    }
                    i = j + 2;
                }
            }
        }
        return stk.empty();
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0591_H
