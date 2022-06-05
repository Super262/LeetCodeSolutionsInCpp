//
// Created by Fengwei Zhang on 12/8/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0470_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0470_H

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
    // 拒绝采样：如果生成的随机数满足要求，那么就返回该随机数，否则会不断生成，直到生成满足要求的随机数为止
    // 我们可以利用两个Rand7()相乘，我们只取其中等概率的10个不同的数的组合即可
    // 我们调用2次Rand7()，生成49个数字（包含重复数字），如下网页所示；我们取出前40个数字，他们的范围在[1:35]
    // 我们将这些数字逐行、逐列映射到1～10，此时1～10中每个数字被生成的概率为4/49
    // https://leetcode-cn.com/problems/implement-rand10-using-rand7/solution/yong-rand7-shi-xian-rand10-by-leetcode-s-qbmd/
public:
    int rand10() {
        int value = 49;
        while (true) {
            auto row_idx = rand7() - 1;
            auto col_idx = rand7() - 1;
            value = row_idx * 7 + col_idx;
            if (value < 40) {
                break;
            }
        }
        return value % 10 + 1;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0470_H
