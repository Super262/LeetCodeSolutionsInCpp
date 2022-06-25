//
// Created by Fengwei Zhang on 6/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0635_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0635_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>

using namespace std;

class LogSystem {
    // 我们将输入的时间字符串ts转换为秒数（从1999年1月1日0时0分0秒开始计算，每月的天数均为31），用有序映射（map）保存"秒数-id"的映射关系
    // 若要查找[start:end]在某个粒度下包含的id，我们分别将start、end也转换为秒数，利用自带函数（二分）查找出ts_2_id中的秒数区间
    // 细节：若当前粒度是"月"，start的月是2016.01、end的月是2017.10，实际的查找范围是[2016.01.01 00:00:00,2017.10.31 23:59:59]
    // 因此，我们应在将ts转换为秒数时特殊处理：若当前ts为查找终点，我们应将它的后缀偏移到最大值
    // 细节：C++会将以"0"开头的数字识别为八进制数字
public:
    LogSystem() {
        gran_to_len["Year"] = 1;
        gran_to_len["Month"] = 2;
        gran_to_len["Day"] = 3;
        gran_to_len["Hour"] = 4;
        gran_to_len["Minute"] = 5;
        gran_to_len["Second"] = 6;
    }

    void put(int id, const string &ts) {
        ts_2_id[secondsFrom1999(ts, 6, false)] = id;
    }

    vector<int> retrieve(const string &start, const string &end, const string &granularity) {
        auto st = secondsFrom1999(start, gran_to_len[granularity], false);
        auto ed = secondsFrom1999(end, gran_to_len[granularity], true);
        auto b = ts_2_id.upper_bound(ed);
        auto a = ts_2_id.lower_bound(st);
        vector<int> ans;
        for (auto it = a; it != b; it++) {
            ans.emplace_back(it->second);
        }
        return ans;
    }

private:
    map<unsigned long long, int> ts_2_id;

    unordered_map<string, int> gran_to_len;  // 不同粒度对应不同的前缀长度

    unsigned long long secondsFrom1999(const string &s, int len, bool move_to_end) {
        // move_to_end：是否将后缀偏移到最大值
        char t[6][5];
        memset(t, 0, sizeof t);
        sscanf(s.c_str(), "%4s:%2s:%2s:%2s:%2s:%2s", t[0], t[1], t[2], t[3], t[4], t[5]);
        unsigned long long nums[len];  // 转换时间s的每部分为整数
        for (int i = 0; i < len; ++i) {
            nums[i] = parseInt(t[i], 4);
        }
        unsigned long long ans = 0;
        unsigned long long base = 12 * 31 * 24 * 60 * 60;
        ans += (nums[0] - 1999) * base;
        if (len == 1) {
            if (move_to_end) {
                ans += base - 1;
            }
            return ans;
        }
        base = 31 * 24 * 60 * 60;
        ans += (nums[1] - 1) * base;
        if (len == 2) {
            if (move_to_end) {
                ans += base - 1;
            }
            return ans;
        }
        base = 24 * 60 * 60;
        ans += (nums[2] - 1) * base;
        if (len == 3) {
            if (move_to_end) {
                ans += base - 1;
            }
            return ans;
        }
        base = 60 * 60;
        ans += nums[3] * base;
        if (len == 4) {
            if (move_to_end) {
                ans += base - 1;
            }
            return ans;
        }
        base = 60;
        ans += nums[4] * base;
        if (len == 5) {
            if (move_to_end) {
                ans += base - 1;
            }
            return ans;
        }
        ans += nums[5];
        return ans;
    }

    unsigned long long parseInt(const char s[], int len) {  // 转换字符串为十进制整数，忽略前导零
        int i = 0;
        while (i < len && s[i] == '0') {
            ++i;
        }
        if (i == len || !s[i]) {
            return 0;
        }
        unsigned long long ans = 0;
        while (i < len && s[i]) {
            ans = ans * 10 + (s[i] - '0');
            ++i;
        }
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0635_H
