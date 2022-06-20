//
// Created by Fengwei Zhang on 6/20/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0604_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0604_H

#include <string>
#include <algorithm>

using namespace std;

class StringIterator {
    // 利用迭代器（string::const_iterator）遍历输入的字符串，查询前先通过hasNext验证
public:
    StringIterator(const string &compressed) {
        ch_idx = compressed.cbegin();
        s_end = compressed.cend();
        updateNextIdx();
    }

    char next() {
        if (hasNext()) {
            --counter;
            return *ch_idx;
        }
        return ' ';
    }

    bool hasNext() {
        if (!counter) {
            ch_idx = next_idx;
            updateNextIdx();
        }
        return ch_idx != s_end;
    }

private:
    string::const_iterator ch_idx;
    string::const_iterator next_idx;
    string::const_iterator s_end;
    int counter;

    void updateNextIdx() {
        if (ch_idx == s_end) {
            return;
        }
        next_idx = ch_idx + 1;
        counter = 0;
        while (next_idx != s_end && isdigit(*next_idx)) {
            counter = counter * 10 + (*next_idx - '0');
            next_idx++;
        }
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0604_H
