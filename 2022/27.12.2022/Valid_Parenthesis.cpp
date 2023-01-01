/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/
class Solution
{
public:
         bool isValid(string S)
         {
                  if (S.size() == 1)
                  {
                           return false;
                  }
                  stack<char> s;
                  for (auto &i : S)
                  {
                           if (i == '(' or i == '[' or i == '{')
                           {
                                    s.push(i);
                           }
                           else if (s.size() <= 0)
                           {
                                    return false;
                           }
                           else if (i == ')' and s.top() == '(')
                           {
                                    s.pop();
                                    cout << "sup" << endl;
                           }
                           else if (i == ']' and s.top() == '[')
                           {
                                    s.pop();
                                    cout << "hey" << endl;
                           }
                           else if (i == '}' and s.top() == '{')
                           {
                                    s.pop();
                           }
                           else
                           {
                                    return false;
                           }
                  }
                  return s.empty();
         }
};