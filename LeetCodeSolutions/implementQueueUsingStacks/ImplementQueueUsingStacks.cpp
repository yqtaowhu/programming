// Date   : 2016.08.05
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Implement the following operations of a queue using stacks.
 * 
 * push(x) -- Push element x to the back of queue.
 * 
 * pop() -- Removes the element from in front of queue.
 * 
 * peek() -- Get the front element.
 * 
 * empty() -- Return whether the queue is empty.
 * 
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to top, 
 * peek/pop from top, size, and is empty operations are valid.

 * Depending on your language, stack may not be supported natively. You may simulate a 
 * stack by using a list or deque (double-ended queue), as long as you use only 
 * standard operations of a stack.

 * You may assume that all operations are valid (for example, no pop or peek operations 
 * will be called on an empty queue).
 *               
 **********************************************************************************/
 //reference :https://discuss.leetcode.com/topic/17974/short-o-1-amortized-c-java-ruby
 /*
 I have one input stack, onto which I push the incoming elements, 
 and one output stack, from which I peek/pop. 
 I move elements from input stack to output stack when needed, i.e.,
 when I need to peek/pop but the output stack is empty. When that happens, 
 I move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.
 The loop in peek does the moving from input to output stack. Each element only ever gets moved like that once, 
 though, and only after we already spent time pushing it, so the overall amortized cost for each operation is O(1).
*/
class Queue {
    stack<int> input, output;
public:

    void push(int x) {
        input.push(x);
    }
    
    void pop(void) {
        peek();
        output.pop();
    }
    
    int peek(void) {
        if (output.empty())
            while (input.size()) {
                output.push(input.top());
                input.pop();
            }
        return output.top();
    }
    
    bool empty(void) {
        return input.empty() && output.empty();
    }
};	

