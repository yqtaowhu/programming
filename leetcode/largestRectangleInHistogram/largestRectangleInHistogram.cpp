// Date   : 2016.08.09
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 * 
 *                    6          
 *                  +---+        
 *               5  |   |        
 *              +---+   |        
 *              |   |   |        
 *              |   |   |        
 *              |   |   |     3  
 *              |   |   |   +---+
 *        2     |   |   | 2 |   |
 *      +---+   |   |   +---+   |
 *      |   | 1 |   |   |   |   |
 *      |   +---+   |   |   |   |
 *      |   |   |   |   |   |   |
 *      +---+---+---+---+---+---+
 *      
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 *      
 *      
 *                    6          
 *                  +---+        
 *               5  |   |        
 *              +-------|        
 *              |-------|        
 *              |-------|        
 *              |-------|     3  
 *              |-------|   +---+
 *        2     |-------| 2 |   |
 *      +---+   |-------|---+   |
 *      |   | 1 |-------|   |   |
 *      |   +---|-------|   |   |
 *      |   |   |-------|   |   |
 *      +---+---+---+---+---+---+
 *      
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * 
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 * 
 *               
 **********************************************************************************/
int largestRectangleArea(vector<int> &height) {
    if (height.size()<=0) return 0;
    //Create an empty stack.
    vector<int> stack;
    //add a flag as a trigger if the end bar is met, and need to check the stack is empty of not .
    height.push_back(0);
    int maxArea = 0;
    for(int i=0; i<height.size(); i++){
        //If stack is empty or height[i] is higher than the bar at top of stack, then push ‘i’ to stack.
        if ( stack.size()<=0 || height[i] >= height[stack.back()] ) {
            stack.push_back(i);
            continue;
        }
        //If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
        //Let the removed bar be height[top]. Calculate area of rectangle with height[top] as smallest bar. 
        //For height[top], the ‘left index’ is previous (previous to top) item in stack and ‘right index’ is ‘i’ (current index).
        int topIdx = stack.back();
        stack.pop_back();
        int area = height[topIdx] * (stack.size()==0 ? i : i - stack.back() - 1 );
        if ( area > maxArea ) {
            maxArea = area;
        }
        //one more time. Because the stack might still have item.
        i--;
    }

    return maxArea;
}
