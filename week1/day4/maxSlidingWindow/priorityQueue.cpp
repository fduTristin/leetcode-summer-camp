#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ret;
        auto cmp = [&](int i, int j) -> bool
        {
            return nums[i] < nums[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        int i;
        for (i = 0; i != k; i++)
        {
            q.push(i);
        }
        ret.push_back(nums[q.top()]);
        for (; i != nums.size(); i++)
        {
            q.push(i);
            while (q.top() <= i - k)
            {
                q.pop();
            }
            ret.push_back(nums[q.top()]);
        }
        return ret;
    }
};