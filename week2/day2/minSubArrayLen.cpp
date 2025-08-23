#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int begin = 0, end = 0;
        int sum = 0, sz = nums.size();
        int ret = sz + 1;
        while (end <= sz)
        {
            if (sum >= target)
            {
                while (sum >= target)
                {
                    sum -= nums[begin];
                    begin++;
                }
                ret = min(ret, end - begin + 1);
            }
            else
            {
                while (end < sz && sum < target)
                {
                    sum += nums[end];
                    end++;
                }
                if (sum < target)
                {
                    break;
                }
            }
        }
        return ret < sz + 1 ? ret : 0;
    }
};