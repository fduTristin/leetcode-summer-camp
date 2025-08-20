#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sz = height.size();
        vector<int> Max(sz, 0);
        int left = 1, right = sz - 2;
        int leftMax = height[0], rightMax = height[sz - 1];
        while (left <= right)
        {
            if (leftMax <= rightMax)
            {
                Max[left] = leftMax;
                leftMax = max(leftMax, height[left]);
                left++;
            }
            else
            {
                Max[right] = rightMax;
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }
        int ret = 0;
        for (int i = 0; i != sz; i++)
        {
            ret += max(0, Max[i] - height[i]);
        }
        return ret;
    }
};