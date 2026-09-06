//
// Created by Fengwei Zhang on 9/6/26.
//

#ifndef LEETCODESOLUTIONSINCPP_PROBLEM2977_H
#define LEETCODESOLUTIONSINCPP_PROBLEM2977_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Problem2977
{
private:
    struct TrieNode
    {
        int word_idx;
        int next[26];

        TrieNode() : word_idx(0)
        {
            memset(next, 0, sizeof(next));
        }
    };

    vector<TrieNode> trieArray;
    int trieNodeIdx;
    int trieWordCount;

    void addWordToTrie(const string &s)
    {
        int node = 0;
        int ch_idx;

        for (char c : s)
        {
            ch_idx = c - 'a';

            if (!trieArray[node].next[ch_idx])
            {
                trieArray[node].next[ch_idx] = ++trieNodeIdx;
                trieArray.emplace_back();
            }

            node = trieArray[node].next[ch_idx];
        }

        if (!trieArray[node].word_idx)
            trieArray[node].word_idx = ++trieWordCount;
    }

    int getWordTrieIdx(const string &s)
    {
        int node = 0;
        int ch_idx;

        for (char c : s)
        {
            ch_idx = c - 'a';

            if (!trieArray[node].next[ch_idx])
                return 0;

            node = trieArray[node].next[ch_idx];
        }

        return trieArray[node].word_idx;
    }

public:
    long long minimumCost(const string& source,
                          const string& target,
                          const vector<string>& original,
                          const vector<string>& changed,
                          const vector<int>& cost)
    {
        trieArray.clear();
        trieArray.emplace_back();

        trieNodeIdx = 0;
        trieWordCount = 0;

        for (const string& s : original)
            addWordToTrie(s);

        for (const string& s : changed)
            addWordToTrie(s);

        vector<vector<int>> dist(trieWordCount + 1,
                                 vector<int>(trieWordCount + 1, -1));

        for (int i = 1; i <= trieWordCount; ++i)
            dist[i][i] = 0;

        for (int i = 0, x, y; i < original.size(); ++i)
        {
            x = getWordTrieIdx(original[i]);
            y = getWordTrieIdx(changed[i]);

            if (dist[x][y] == -1)
                dist[x][y] = cost[i];
            else
                dist[x][y] = min(dist[x][y], cost[i]);
        }

        // Floyd
        for (int mid = 1; mid <= trieWordCount; ++mid)
        {
            for (int st = 1; st <= trieWordCount; ++st)
            {
                if (dist[st][mid] == -1)
                    continue;

                for (int ed = 1, new_dist; ed <= trieWordCount; ++ed)
                {
                    if (dist[mid][ed] == -1)
                        continue;

                    new_dist = dist[st][mid] + dist[mid][ed];

                    if (dist[st][ed] == -1)
                        dist[st][ed] = new_dist;
                    else
                        dist[st][ed] = min(dist[st][ed], new_dist);
                }
            }
        }

        int n = (int)source.size();

        // dp[i] = cost to convert first i characters
        vector<long long> dp(n + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; ++i)
        {
            if (dp[i] == -1)
                continue;

            // source[i] 不需要改变
            if (source[i] == target[i])
            {
                if (dp[i + 1] == -1)
                    dp[i + 1] = dp[i];
                else
                    dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // source[i...j] -> target[i...j]
            long long cur;
            for (int j = i, x, y, x_node = 0, y_node = 0; j < n; ++j)
            {
                int x_ch = source[j] - 'a';
                int y_ch = target[j] - 'a';

                if (!trieArray[x_node].next[x_ch] ||
                    !trieArray[y_node].next[y_ch])
                    break;

                x_node = trieArray[x_node].next[x_ch];
                y_node = trieArray[y_node].next[y_ch];

                x = trieArray[x_node].word_idx;
                y = trieArray[y_node].word_idx;

                if (!x || !y)
                    continue;

                if (dist[x][y] == -1)
                    continue;

                cur = dp[i] + dist[x][y];

                if (dp[j + 1] == -1)
                    dp[j + 1] = cur;
                else
                    dp[j + 1] = min(dp[j + 1], cur);
            }
        }

        return dp[n];
    }
};
#endif //LEETCODESOLUTIONSINCPP_PROBLEM2977_H
