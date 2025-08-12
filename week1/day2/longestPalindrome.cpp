#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int sz = s.size();
        vector<vector<bool>> d(sz);
        int maxLen = 1, begin;
        for (int i = 0; i != sz; i++)
        {
            d[i] = vector<bool>(sz, false);
            d[i][i] = true;
            if (i >= 1 && s[i] == s[i - 1])
            {
                d[i - 1][i] = true;
                begin = i - 1;
                maxLen = 2;
            }
        }
        for (int l = 2; l != sz; l++)
        {
            int left = 0;
            while (left + l != sz)
            {
                if (d[left + 1][left + l - 1] && (s[left] == s[left + l]))
                {
                    d[left][left + l] = true;
                    begin = left;
                    maxLen = l + 1;
                }
                left++;
            }
        }
        return s.substr(begin, maxLen);
    }
};