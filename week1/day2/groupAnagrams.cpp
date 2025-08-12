#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include<array>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        auto myHash = [f = hash<int>{}](const array<int, 26> &arr) -> size_t
        {
            size_t ret = 0;
            for (int i = 0; i != 26; i++)
            {
                ret = (ret << 1) ^ arr[i];
            }
            return ret;
        };
        unordered_map<array<int,26>, vector<string>, decltype(myHash)> map(0, myHash);

        for(string str:strs){
            array<int, 26> cnt = {0};
            for(char c:str){
                cnt[c-'a']++;
            }
            map[cnt].push_back(str);
        }

        vector<vector<string>> ret;
        for(auto kv: map){
            ret.push_back(kv.second);
        }

        return ret;
    }
};