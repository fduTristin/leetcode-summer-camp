#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> s,sMin;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if(!s.empty()){
            int currentMin = min(sMin.top(), val);
            s.push(val);
            sMin.push(currentMin);
        }
        else{
            s.push(val);
            sMin.push(val);
        }
    }

    void pop()
    {
        s.pop();
        sMin.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return sMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */