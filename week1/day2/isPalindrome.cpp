#include <string>

using namespace std;

// DP

class Solution
{
public:
    bool isCharacterOrNumber(char c)
    {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')|| (c >= '0' && c <= '9');
    }
    bool isLowercase(char c)
    {
        return c >= 'a' && c <= 'z';
    }
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if(!isCharacterOrNumber(s[i]))
            {
                i++;
                continue;
            }
            if(!isCharacterOrNumber(s[j]))
            {
                j--;
                continue;
            }
            if ((isLowercase(s[i]) ? s[i] - 'a' : s[i] - 'A') != (isLowercase(s[j]) ? s[j] - 'a' : s[j] - 'A'))
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};