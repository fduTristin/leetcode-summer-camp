#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int lenS = s.size(), lenT = t.size();
        if (lenS == 0 || lenS < lenT)
        {
            return "";
        }
        int cnt[52] = {0};
        for (char c : t)
        {
            if (c >= 'a' && c <= 'z')
            {
                cnt[c - 'a']--;
            }
            else
            {
                cnt[c - 'A' + 26]--;
            }
        }
        int start = 0, end = 0, diff = lenT;
        string ret = "";
        int minLen = lenS + 1;
        while (1)
        {
            if (diff > 0)
            {
                if (end >= lenS)
                {
                    break;
                }
                int idx = s[end] >= 'a' && s[end] <= 'z' ? s[end] - 'a' : s[end] - 'A' + 26;
                end++;
                ++cnt[idx];
                if (cnt[idx] <= 0)
                {
                    diff--;
                }
            }
            else
            {
                int idx = s[start] >= 'a' && s[start] <= 'z' ? s[start] - 'a' : s[start] - 'A' + 26;
                --cnt[idx];
                if (cnt[idx] < 0)
                {
                    diff++;
                    if (minLen > end - start)
                    {
                        minLen = end - start;
                        ret = s.substr(start, minLen);
                    }
                }
                start++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = solution.minWindow(s, t);
    printf("The minimum window substring is: %s\n", result.c_str());
    return 0;
}