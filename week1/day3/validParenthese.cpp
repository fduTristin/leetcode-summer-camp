#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        if (s.size() % 2)
            return false;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stk.push(c);
            }
            else if (stk.empty())
                return false;
            else if (c == ')')
            {
                if (stk.top() != '(')
                    return false;
                stk.pop();
            }
            else if (c == ']')
            {
                if (stk.top() != '[')
                    return false;
                stk.pop();
            }
            else if (c == '}')
            {
                if (stk.top() != '{')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};