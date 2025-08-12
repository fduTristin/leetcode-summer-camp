#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> s;
        vector<int> ret(temperatures.size());
        for (int i = 0; i != temperatures.size(); i++)
        {
            while (!s.empty() && temperatures[s.top()] < temperatures[i])
            {
                int day = s.top();
                ret[day] = i - day;
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};