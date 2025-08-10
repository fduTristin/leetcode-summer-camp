#include <vector>

using namespace std;

// DP

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxProduct = max(0, nums[0]), minProduct = min(0, nums[0]), ret = nums[0];
        for (int i = 1; i != nums.size(); i++)
        {
            int n = nums[i];
            if (n < 0)
            {
                int temp = maxProduct;
                maxProduct = max(n, minProduct * n);
                minProduct = min(n, temp * n);
            }
            else
            {
                maxProduct = max(n, maxProduct * n);
                minProduct = min(n, minProduct * n);
            }
            ret = max(ret, maxProduct);
        }
        return ret;
    }
};