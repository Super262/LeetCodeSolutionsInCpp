//
// Created by Fengwei Zhang on 7/8/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0702_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0702_H

class ArrayReader {
public:
    int get(int index) const;
};

class Solution {
    // 先确定可能的查找区间[l:r]：向右扩展r，l=r，r*=2，直到reader.get(r)>=target
    // 在区间[l:r]内执行二分查找，若最终找到target，返回对应的索引
public:
    int search(const ArrayReader &reader, int target) {
        if (reader.get(0) == target) {
            return 0;
        }
        if (reader.get(0) > target) {
            return -1;
        }
        int l = 0;
        int r = 1;
        while (reader.get(r) < target) {
            l = r;
            r <<= 1;
        }
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (reader.get(mid) >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (reader.get(r) != target) {
            return -1;
        }
        return r;
    }
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0702_H
