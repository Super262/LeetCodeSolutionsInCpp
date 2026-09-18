//
// Created by Fengwei Zhang on 10/3/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM1048_H
#define LEETCODESOLUTIONSINCPP_PROBLEM1048_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Problem1048
{
public:
    /*
    ** 先对words按照长度排序，
    ** 确保当 i >= j 时，words[i]不是words[j]的前序单词
    ** f[i]：以words[i]结尾的最长的单词链的长度
    */
    int longestStrChain(vector<string>& words)
    {
        /* 按长度排序 */
        sort(words.begin(), words.end(),
             [](const string &w1, const string &w2){return w1.size() < w2.size();});

        const int &n = (int)words.size();
        vector<int> f(n, 1);
        int answer = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i - 1, t; j >= 0; --j)
            {
                if (words[j].size() == words[i].size())
                    continue;

                if (words[j].size() + 1 < words[i].size())
                    break;
                
                if (checkPredecessor(words[j], words[i]))
                {
                    int t = f[j] + 1;

                    if (t > f[i])
                    {
                        f[i] = t;
                        if (t > answer)
                            answer = t;
                    }
                }
            }
        }

        return answer;
    }

private:
    /* 若a是b的前序单词，返回true。 */
    bool checkPredecessor(const string &a, const string &b)
    {
        if (a.size() + 1 != b.size())
            return false;
        
        for (int pivot = 0, i; pivot < (int) b.size(); ++pivot)
        {
            for (i = 0; i < pivot && i < (int) a.size(); ++i)
            {
                if (a[i] != b[i])
                    break;
            }

            if (i != pivot)
                continue;
            
            while (i < (int) a.size())
            {
                if (i + 1 >= (int) b.size())
                    break;
                
                if (a[i] != b[i + 1])
                    break;
                
                ++i;
            }

            if (i == (int)a.size() && i + 1 == (int)b.size())
                return true;
        }

        return false;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM1048_H
