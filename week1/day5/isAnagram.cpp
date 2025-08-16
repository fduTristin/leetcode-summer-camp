#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> smap, tmap;
        for (int i = 0; i != 26; i++)
        {
            smap['a' + i] = 0;
            tmap['a' + i] = 0;
        }
        for (char c : s)
        {
            smap[c]++;
        }
        for (char c : t)
        {
            tmap[c]++;
        }
        for (auto it = smap.begin(); it != smap.end(); it++)
        {
            if (smap[it->first] != tmap[it->first])
            {
                return false;
            }
        }
        return true;
    }
};