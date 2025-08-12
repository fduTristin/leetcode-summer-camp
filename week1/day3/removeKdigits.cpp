#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int top(const vector<int> &stk)
    {
        return *(stk.end() - 1);
    }
    string removeKdigits(string num, int k)
    {
        vector<int> stack;

        int i = 0, j = k;
        while (j > 0 && i < num.size())
        {
            if (!stack.empty() && num[top(stack)] > num[i])
            {
                stack.pop_back();
                j--;
                continue;
            }
            stack.push_back(i);
            i++;
        }
        string ret;
        cout<<"i: "<< i <<endl;
        for (int l = 0; l != stack.size(); l++)
        {
            ret += num[stack[l]];
        }

        if (i < num.size())
        {
            ret += num.substr(i, num.size() - i);
        }

        else
        {
            ret = ret.substr(0, num.size() - k);
        }
        cout << ret << endl;
        int begin = 0;
        while (begin < ret.size())
        {
            if (ret[begin] == '0')
            {
                begin++;
            }
            else
            {
                break;
            }
        }
        ret = ret.substr(begin, ret.size() - begin);
        return ret == "" ? "0" : ret;
    }
};

int main()
{
    Solution sol;
    vector<pair<string, int>> tests = {
        {"21", 1}};

    for (auto &t : tests)
    {
        string result = sol.removeKdigits(t.first, t.second);
        cout << "removeKdigits(" << t.first << ", " << t.second << ") = " << result << endl;
    }

    return 0;
}