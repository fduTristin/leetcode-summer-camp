#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 前缀和 + 哈希

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        size_t sz = nums.size();
        vector<int> prefixSum(sz);
        int sum = 0;
        for (int i = 0; i != sz; i++)
        {
            sum += nums[i];
            prefixSum[i] = sum;
        }

        unordered_map<int, int> map;
        map[k] = 1;
        int ret = 0;

        for (int i = 0; i != sz; i++)
        {
            if (map.find(prefixSum[i]) != map.end())
            {
                ret += map[prefixSum[i]];
            }
            int temp = prefixSum[i] + k;
            if (map.find(temp) == map.end())
            {
                map[temp] = 1;
            }
            else
            {
                map[temp]++;
            }
        }
        return ret;
    }
};