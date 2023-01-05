/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

*/
class Solution
{
public:
         int evalRPN(vector<string> &tokens)
         {
                  stack<int> s;
                  long int num1, num2, calculatedSoFar;
                  for (const auto &i : tokens)
                  {
                           if (i == "/" or i == "*" or i == "+" or i == "-")
                           {
                                    num1 = s.top();
                                    s.pop();
                                    num2 = s.top();
                                    s.pop();
                                    cout << "num1 :" << num1 << " num2 :" << num2 << " operator :" << i << endl;

                                    if (i == "/")
                                    {
                                             calculatedSoFar = num2 / num1;
                                    }
                                    else if (i == "*")
                                    {
                                             calculatedSoFar = num2 * num1;
                                    }
                                    else if (i == "+")
                                    {
                                             calculatedSoFar = num2 + num1;
                                    }
                                    else
                                    {
                                             calculatedSoFar = num2 - num1;
                                    }
                                    s.push(calculatedSoFar);
                           }
                           else
                           {
                                    s.push(stoi(i));
                           }
                  }
                  cout << s.size() << endl;
                  return s.top();
         }
};