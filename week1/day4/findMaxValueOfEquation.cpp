#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        deque<int> q;
        int ret = -__INT32_MAX__;
        for (int i = 0; i != points.size(); i++)
        {
            while (!q.empty() && points[q.front()][0] + k < points[i][0])
            {
                q.pop_front();
            }
            while (!q.empty() && points[q.back()][1] - points[q.back()][0] <= points[i][1] - points[i][0])
            {
                if (q.size() == 1)
                {
                    ret = max(ret, points[q.back()][1] + points[i][1] + points[i][0] - points[q.back()][0]);
                }
                q.pop_back();
            }
            if (!q.empty())
            {
                ret = max(ret, points[q.front()][1] + points[i][1] + points[i][0] - points[q.front()][0]);
            }
            q.push_back(i);
        }
        return ret;
    }
};