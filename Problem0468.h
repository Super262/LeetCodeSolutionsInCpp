//
// Created by Fengwei Zhang on 1/22/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0468_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0468_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string validIPAddress(const string &ip) {
        if (ip.find('.') != string::npos) {
            return checkIPv4(ip);
        }
        if (ip.find(':') != string::npos) {
            return checkIPv6(ip);
        }
        return "Neither";
    }

private:
    string checkIPv4(const string &ip) {
        auto items = split(ip, '.');
        if (items.size() != 4) {
            return "Neither";
        }
        for (const auto &item: items) {
            if (item.empty() || item.size() > 3) {
                return "Neither";
            }
            if (item.size() > 1 && item[0] == '0') {
                return "Neither";
            }
            for (const auto &ch: item) {
                if (!isdigit(ch)) {
                    return "Neither";
                }
            }
            auto t = stoi(item);
            if (t > 255) {
                return "Neither";
            }
        }
        return "IPv4";
    }

    string checkIPv6(const string &ip) {
        auto items = split(ip, ':');
        if (items.size() != 8) {
            return "Neither";
        }
        for (const auto &item: items) {
            if (item.empty() || item.size() > 4 || !isHex(item)) {
                return "Neither";
            }
        }
        return "IPv6";
    }

    vector<string> split(const string &ip, char t) {
        string temp;
        vector<string> items;
        for (const auto &ch: ip) {
            if (ch == t) {
                items.emplace_back(temp);
                temp.clear();
            } else {
                temp.push_back(ch);
            }
        }
        items.emplace_back(temp);
        return items;
    }

    bool isHex(const string &s) {
        for (const auto &ch: s) {
            if (isdigit(ch)) {
                continue;
            }
            if (ch >= 'A' && ch <= 'F') {
                continue;
            }
            if (ch >= 'a' && ch <= 'f') {
                continue;
            }
            return false;
        }
        return true;
    }
};



#endif //LEETCODESOLUTIONSINCPP_PROBLEM0468_H
