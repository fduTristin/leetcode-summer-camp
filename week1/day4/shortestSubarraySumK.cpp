#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        deque<int> q;
        int sz = nums.size();
        vector<long long> prefixSum(sz + 1, 0);
        for (int i = 0; i < sz; i++)
        {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int ret = sz + 1;
        for (int i = 0; i <= sz; i++)
        {
            while (!q.empty() && prefixSum[q.front()] + k <= prefixSum[i])
            {
                ret = min(ret, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && prefixSum[q.back()] >= prefixSum[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ret <= sz ? ret : -1;
    }
};