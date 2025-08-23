#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> pMap, wMap;
        vector<int> ret = {};
        if (p.size() == 0 || s.size() < p.size())
            return ret;
        for (char c : p)
        {
            if (pMap.find(c) == pMap.end())
            {
                pMap[c] = 1;
            }
            else
            {
                pMap[c]++;
            }
        }
        int begin = 0, end = p.size() - 1;
        for (int i = 0; i <= end; i++)
        {
            if (wMap.find(s[i]) == wMap.end())
            {
                wMap[s[i]] = 1;
            }
            else
            {
                wMap[s[i]]++;
            }
        }
        for (auto it = pMap.begin(); it != pMap.end(); it++)
        {
            char c = it->first;
            int n = it->second;
            if (wMap.find(c) != wMap.end())
            {
                wMap[c] -= pMap[c];
                if (wMap[c] == 0)
                {
                    wMap.erase(c);
                }
            }
            else
            {
                wMap[c] = -pMap[c];
            }
        }
        if (wMap.size() == 0)
        {
            ret.push_back(0);
        }

        while (end < s.size() - 1)
        {
            begin++;
            end++;
            char b = s[begin - 1], e = s[end];
            if (wMap.find(b) == wMap.end())
            {
                wMap[b] = -1;
            }
            else
            {
                wMap[b] -= 1;
                if (wMap[b] == 0)
                {
                    wMap.erase(b);
                }
            }
            if (wMap.find(e) == wMap.end())
            {
                wMap[e] = 1;
            }
            else
            {
                wMap[e] += 1;
                if (wMap[e] == 0)
                {
                    wMap.erase(e);
                }
            }
            if (wMap.size() == 0)
            {
                ret.push_back(begin);
            }
        }
        return ret;
    }
};