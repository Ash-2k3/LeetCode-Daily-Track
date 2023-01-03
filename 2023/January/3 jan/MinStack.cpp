/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

class MinStack
{
private:
         vector<pair<int, int>> s;
         int nextIndex, lastIndex, minElement;

public:
         MinStack()
         {
                  nextIndex = 0;
                  lastIndex = -1;
                  minElement = INT_MAX;
         }

         void push(int val)
         {
                  pair<int, int> p = {val, min(minElement, val)};
                  minElement = p.second;
                  // s[nextIndex++] = p ;
                  s.push_back(p);
                  ++lastIndex;
         }

         void pop()
         {
                  // --nextIndex;
                  s.pop_back();
                  --lastIndex;
                  if (lastIndex < 0)
                  {
                           minElement = INT_MAX;
                           return;
                  }
                  minElement = s[lastIndex].second;
         }

         int top()
         {
                  return s[lastIndex].first;
         }

         int getMin()
         {
                  return minElement;
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