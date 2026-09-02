//
// Created by Fengwei Zhang on 10/2/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0060_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0060_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Problem0060 {
public:
    string getPermutation(int n, int k)
    {
        /* （逆）康托展开：https://zhuanlan.zhihu.com/p/109700398 */
        vector<int> fact;
        vector<int> nums;
        string answer;
    
        nums.reserve(n);
        fact.reserve(n + 1);
        fact.emplace_back(1);
        answer.reserve(n + 1);

        for (int i = 1; i <= n; ++i)
        {
            nums.emplace_back(i);
            fact.emplace_back(fact.back() * i);
        }
        
        /* 知乎文章里的k是0-based，这里的输入是1-based，所以我们先减1 */
        --k；
        for (int i = n, idx, r; i > 0; --i)
        {
            idx = k / fact[i - 1];
            r = k % fact[i - 1];
            answer += (char)(nums[idx] + '0');
            nums.erase(nums.begin() + idx);
            k = r;
        }

        return answer;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0060_H
