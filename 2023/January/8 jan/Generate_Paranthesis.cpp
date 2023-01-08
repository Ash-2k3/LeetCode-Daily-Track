/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

class Solution
{
private:
         vector<string> ans;

         void helper(int openB, int closeB, stack<char> s, string str)
         {
                  if (openB == 0 and closeB == 0)
                  {
                           ans.push_back(str);
                           return;
                  }
                  if (s.size() == 0)
                  {
                           s.push('(');
                           helper(openB - 1, closeB, s, str + '(');
                           s.pop();
                  }
                  else if (s.top() == '(')
                  {
                           if (openB > 0)
                           {
                                    s.push('(');
                                    helper(openB - 1, closeB, s, str + '(');
                                    s.pop();
                           }
                           if (closeB > 0)
                           {
                                    s.pop();
                                    helper(openB, closeB - 1, s, str + ')');
                           }
                  }
         }

public:
         vector<string> generateParenthesis(int n)
         {
                  stack<char> s;
                  string str;
                  helper(n, n, s, str);
                  return ans;
         }
};
