#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2)
        {
            return false;
        }
        int cnt[26] = {0};
        for (char c : s1)
        {
            cnt[c - 'a']--;
        }
        int same = 0;
        for (int i = 0; i != len1; i++)
        {
            int idx = s2[i] - 'a';
            ++cnt[idx];
            if (cnt[idx] <= 0)
            {
                same++;
            }
        }
        if (same == len1)
        {
            return true;
        }
        for (int i = len1; i != len2; i++)
        {
            int idx1 = s2[i - len1] - 'a';
            int idx2 = s2[i] - 'a';
            --cnt[idx1];
            if (cnt[idx1] < 0)
            {
                same--;
            }
            ++cnt[idx2];
            if (cnt[idx2] <= 0)
            {
                same++;
            }
            // cout << "substr of s2: " << s2.substr(i - len1 + 1, len1) << ", same: " << same << endl;
            if (same == len1)
            {
                // cout << "substr of s2: " << s2.substr(i - len1 + 1, len1) << endl;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string s1 = "hello";
    string s2 = "ooolleoooleh";
    bool result = solution.checkInclusion(s1, s2);
    if (result)
    {
        printf("The string '%s' contains a permutation of '%s'.\n", s2.c_str(), s1.c_str());
    }
    else
    {
        printf("The string '%s' does not contain a permutation of '%s'.\n", s2.c_str(), s1.c_str());
    }
    return 0;
}