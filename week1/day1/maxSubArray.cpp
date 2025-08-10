#include <vector>

using namespace std;

// 前缀和解法

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, minSum = 0, ret = min(0, nums[0]);
        for (int n : nums)
        {
            sum += n;
            ret = max(ret, sum - minSum);
            minSum = min(minSum, sum);
        }
        return ret;
    }
};