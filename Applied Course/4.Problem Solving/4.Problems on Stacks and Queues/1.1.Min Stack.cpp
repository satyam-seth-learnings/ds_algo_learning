#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s,ss;
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if(ss.size()==0 || x<=ss.top())
            ss.push(x);
    }
    
    void pop() {
        if(s.top()==ss.top())
            ss.pop();
        s.pop();
    }
    
    int top() {
        if(s.size()==0)
            return -1;
        else
            return s.top();
    }
    
    int getMin() {
        if(ss.size()==0)
            return -1;
        else
            return ss.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    // https://leetcode.com/problems/min-stack/
    return 0;
}