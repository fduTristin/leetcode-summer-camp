#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int ret = 0;
        unordered_set<int> set;

        for (int n : nums)
        {
            set.insert(n);
        }

        for (int n : set)
        {
            if (!set.count(n - 1))
            {
                int next = n + 1;
                while (set.count(next))
                {
                    next++;
                }
                ret = max(ret, next - n);
            }
        }
        return ret;
    }
};