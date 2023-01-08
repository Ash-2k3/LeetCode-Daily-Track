/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/
class Solution
{
public:
         vector<int> dailyTemperatures(vector<int> &temperatures)
         {
                  vector<int> ans(temperatures.size(), 0);
                  stack<pair<int, int>> s;
                  s.push({temperatures[0], 0});
                  for (int i = 1; i < temperatures.size(); i++)
                  {
                           while (!s.empty() && temperatures[i] > s.top().first)
                           {
                                    ans[s.top().second] = i - s.top().second;
                                    s.pop();
                           }
                           s.push({temperatures[i], i});
                  }
                  return ans;
         }
};