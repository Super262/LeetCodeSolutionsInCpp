//
// Created by Fengwei Zhang on 4/18/22.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM0966_H
#define LEETCODESOLUTIONSINCPP_PROBLEM0966_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    // 数据范围大，不能直接遍历，要用哈希表加速：预存储所有可能的错误情况
    // 3个哈希表，分别处理原串、大写错误、元音错误
public:
    vector<string> spellchecker(const vector<string> &words, const vector<string> &queries) {
        // 哈希表(s:i)：(错误串，正确值的索引)
        unordered_set<string> raw(words.begin(), words.end());
        unordered_map<string, int> lower_case;
        unordered_map<string, int> vowels_altered;  // 检查元音时，大小写不敏感
        const auto n = (int) words.size();
        for (int i = 0; i < n; ++i) {  // 预处理，保存最近的、符合要求的正确单词
            auto sl = lowerStr(words[i]);
            if (!lower_case.count(sl)) {
                lower_case[sl] = i;
            }
            shadowVowels(sl);
            if (!vowels_altered.count(sl)) {
                vowels_altered[sl] = i;
            }
        }
        vector<string> ans(queries.size());
        for (int i = 0; i < (int) queries.size(); ++i) {
            if (raw.count(queries[i])) {
                ans[i] = queries[i];
                continue;
            }
            auto sl = lowerStr(queries[i]);
            if (lower_case.count(sl)) {
                ans[i] = words[lower_case[sl]];
                continue;
            }
            shadowVowels(sl);
            if (vowels_altered.count(sl)) {
                ans[i] = words[vowels_altered[sl]];
                continue;
            }
            ans[i] = "";
        }
        return ans;
    }

private:
    static string lowerStr(const string &s) {  // 转换s为小写
        string ans(s.size(), '\0');
        for (int i = 0; i < (int) s.size(); ++i) {
            ans[i] = (char) tolower(s[i]);
        }
        return ans;
    }

    void shadowVowels(string &s) {  // 我们将所有元音全部替换为"#"，来匹配所有可能的元音错误
        for (char &ch: s) {
            if (!VOWELS.count(ch)) {
                continue;
            }
            ch = '#';
        }
    }

    const unordered_set<char> VOWELS = {'a', 'e', 'i', 'o', 'u'};
};

#endif //LEETCODESOLUTIONSINCPP_PROBLEM0966_H
