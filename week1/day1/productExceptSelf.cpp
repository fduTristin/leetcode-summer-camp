#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        size_t sz = nums.size();
        int temp = 1;
        vector<int> ret(sz, 1);
        for (int i = 0; i != sz; i++)
        {
            ret[i] *= temp;
            temp *= nums[i];
        }
        temp = 1;
        for (int i = sz - 1; i != -1; i--)
        {
            ret[i] *= temp;
            temp *= nums[i];
        }
        return ret;
    }
};