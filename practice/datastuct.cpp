//implement a data stucture of min stack
//can using two stack to slove this problem
class Solution {
public:
    stack<int> s1;
    stack<int> s2;
    void push(int value) {
        if (s2.empty()||value<=min()) 
            s2.push(value);
        s1.push(value);
    }
    void pop() {
        if (s1.top()==s2.top()) 
            s2.pop();
        s1.pop();
    }
    int top() {
      return s1.top();
    }
    int min() {
        return s2.top();
    }
};
