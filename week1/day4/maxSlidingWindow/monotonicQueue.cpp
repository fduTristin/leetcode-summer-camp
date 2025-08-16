#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ret;
        deque<int> q;
        int i;
        for (i = 0; i != k; i++)
        {
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        ret.push_back(nums[q.front()]);
        for (; i != nums.size(); i++)
        {
            if (q.front() <= i - k)
            {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};