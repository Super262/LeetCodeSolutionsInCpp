//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0157_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0157_H

#include <algorithm>

using namespace std;

int read4(char *buf4);

class Problem0157 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int result = 0;
        int cnt = 0;
        for (int i = 0; i < n; i += cnt) {
            cnt = read4(buf + i);
            if (cnt == 0) {  // 没有读到新字符，终止程序
                return result;
            }
            result += cnt;
        }
        return min(result, n); // 读到的字符不能超过n
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0157_H
