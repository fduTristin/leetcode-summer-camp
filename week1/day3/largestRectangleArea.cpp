#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int sz = heights.size();
        vector<int> left(sz, -1), right(sz, sz);
        stack<int> s;
        int ret = 0;
        for (int i = 0; i != sz; i++)
        {

            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                left[i] = s.top();
            }
            s.push(i);
        }
        s = stack<int>();
        for (int i = sz - 1; i >= 0; i--)
        {

            while (!s.empty() && heights[s.top()] >= heights[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                right[i] = s.top();
            }
            s.push(i);
            ret = max(ret, (right[i] - left[i] - 1) * heights[i]);
        }
        return ret;
    }
};