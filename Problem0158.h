//
// Created by Fengwei Zhang on 11/11/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0158_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0158_H

int read4(char *buf4);

class Problem0158 {
private:
    char temp[4]{};  // 缓存
    int hh = 0;  // 缓存头索引
    int tt = -1;  // 缓存尾索引

public:

    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, const int &n) {
        int ans = 0;
        int size = 0;  // buf当前长度
        int cnt;  // 每次被存入buf的字符个数
        for (int i = 0; i < n; i += cnt) {
            if (tt >= hh) {  // 缓存不为空
                cnt = 1;
                buf[size++] = temp[hh++];
                ++ans;
            } else {  // 缓存为空，需要读取新数据
                cnt = read4(temp);
                if (cnt == 0) {  // 没有新数据，终止
                    return ans;
                }
                hh = 0, tt = cnt - 1;  // 重置指针
                if (i + cnt > n) {  // 总字符数超过n
                    cnt = n - i;
                }
                for (int j = 0; j < cnt; ++j) {
                    buf[size++] = temp[hh++];
                    ++ans;
                }
            }
        }
        return ans;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0158_H
