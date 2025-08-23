#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> set;
        for (int i = 0; i <= k && i < nums.size(); i++)
        {
            if (set.find(nums[i]) != set.end())
            {
                return true;
            }
            set.insert(nums[i]);
        }
        for (int i = k + 1; i < nums.size(); i++)
        {
            set.erase(nums[i - k - 1]);
            if (set.find(nums[i]) != set.end())
            {
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }
};
