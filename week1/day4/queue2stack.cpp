#include <queue>

using namespace std;

class MyStack
{
private:
    queue<int> q, q1;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
        while (!q.empty())
        {
            q1.push(q.front());
            q.pop();
        }
        queue<int> q2 = q;
        q = q1;
        q1 = q2;
    }

    int pop()
    {
        int ret = top();
        q.pop();
        return ret;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};