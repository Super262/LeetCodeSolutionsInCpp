//
// Created by Fengwei Zhang on 5/24/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0359_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0359_H

#include <string>
#include <unordered_map>

using namespace std;

class Logger {
public:
    Logger() = default;

    bool shouldPrintMessage(int timestamp, const string &message) {
        if (!print_time.count(message) || timestamp >= print_time[message]) {
            print_time[message] = timestamp + 10;
            return true;
        }
        return false;
    }

private:
    unordered_map<string, int> print_time;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0359_H
