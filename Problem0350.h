//
// Created by Fengwei Zhang on 11/24/21.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0350_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0350_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    // 1.若数组已经有序，我们可以使用双指针算法，保持 *p2 <= *p1
    // 2.若nums1比nums2小很多，则将nums1全部放入哈希集合中的做法更好
    // 3.若nums2很大，无法被加载到内存，怎么办？
    //   如果nums1可以被读入内存，将nums1全部放入内存，逐个遍历nums2；
    //   如果nums1不能被读入内存，则将num1、nums2外部排序（External Sorting），采用双指针算法。
public:
    vector<int> intersect(const vector<int> &nums1, const vector<int> &nums2) {
        unordered_multiset<int> allNums(nums1.begin(), nums1.end());
        vector<int> res;
        for (const auto &x: nums2) {
            if (!allNums.count(x)) {
                continue;
            }
            allNums.erase(allNums.find(x));
            res.push_back(x);
        }
        return res;
    }
};


#endif //LEETCODESOLUTIONSINCPP_PROBLEM0350_H
