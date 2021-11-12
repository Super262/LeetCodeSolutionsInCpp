//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0158_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0158_H

int read4(char *buf4);

class Problem0158 {
private:
    char temp[4];  // 缓存
    int hh = 0;  // 缓存头索引
    int tt = -1;  // 缓存尾索引

public:

    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, const int &n) {
        int result = 0;
        int size = 0;  // buf当前长度
        int cnt;
        for (int i = 0; i < n; i += cnt) {
            if (tt >= hh) {
                cnt = 1;
                buf[size++] = temp[hh++];
                ++result;
            } else {
                cnt = read4(temp);
                if (cnt == 0) {
                    return result;
                }
                hh = 0, tt = cnt - 1;
                if (i + cnt > n) {
                    cnt = n - i;
                }
                for (int j = 0; j < cnt; ++j) {
                    buf[size++] = temp[hh++];
                    ++result;
                }
            }
        }
        return result;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0158_H
