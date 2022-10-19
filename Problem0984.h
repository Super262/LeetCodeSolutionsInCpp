//
// Created by Fengwei Zhang on 4/19/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0984_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0984_H

#include <string>

using namespace std;

class Problem0984 {
    // "a"多于"b"时，我们优先放置"aab"，再放置"ab"；"b"多于"a"时同理
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        ans.reserve(a + b);
        if (a >= b) {
            while (a > 0 || b > 0) {
                if (a > b) {
                    ans += "aab";
                    a -= 2;
                    --b;
                } else {
                    ans += "ab";
                    --a;
                    --b;
                }
            }
        } else {
            while (a > 0 || b > 0) {
                if (b > a) {
                    ans += "bba";
                    --a;
                    b -= 2;
                } else {
                    ans += "ba";
                    --a;
                    --b;
                }
            }
        }
        for (int i = 0; i < abs(a + b); ++i) {   // 弹出多余的字符
            ans.pop_back();
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0984_H
