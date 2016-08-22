// Date   : 2016.08.22
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
* 
* push(x) -- Push element x onto stack.
* 
* pop() -- Removes the element on top of the stack.
* 
* top() -- Get the top element.
* 
* getMin() -- Retrieve the minimum element in the stack.
* /**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
*               
**********************************************************************************/
//uising two stack
class MinStack {
public:
    /** initialize your data structure here. */
     stack<int> s1;
     stack<int> s2;
    MinStack() { }
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

//using one stack
class MinStack {
public:
    MinStack(): m_min(INT_MAX){}
    void push(int x) {
        if(x <= m_min){
            m_stack.push(m_min);
            m_min = x;
        }
        m_stack.push(x);
    }
    void pop() {
        if(m_stack.top() == m_min){
            m_stack.pop();
            m_min = m_stack.top();
            m_stack.pop();
        } else {
            m_stack.pop();
        }
        
        if(m_stack.empty()) m_min = INT_MAX;
    }

    int top() {
        return m_stack.top();
    }

    int getMin() {
        return m_min;
    }
private:
    stack<int> m_stack;
    int m_min;
};
