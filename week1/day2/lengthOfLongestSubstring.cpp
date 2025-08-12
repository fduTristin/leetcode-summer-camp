#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// 滑动窗口 + 哈希
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        unordered_map<char, int> map;
        int ret = 0;
        for (int i = 0; i != s.size(); i++)
        {
            if (map.find(s[i]) != map.end())
            {
                if (map[s[i]] >= left)
                {
                    ret = max(ret, i - left);
                    left = map[s[i]] + 1;
                }
                map[s[i]] = i;
            }
            else
            {
                map[s[i]] = i;
            }
            if (i == s.size() - 1)
            {
                ret = max(ret, i - left + 1);
            }
        }
        return ret;
    }
};