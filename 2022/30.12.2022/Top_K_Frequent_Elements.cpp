/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 */

class Solution
{

public:
         vector<int> topKFrequent(vector<int> &nums, int k)
         {
                  unordered_map<int, int> map;
                  for (const auto &i : nums)
                  {
                           map[i]++;
                  }
                  priority_queue<pair<int, int>> pq;
                  for (auto &i : map)
                  {
                           pair<int, int> p;
                           p.first = i.second;
                           p.second = i.first;
                           pq.push(p);
                  }
                  vector<int> ans;
                  for (int i = 1; i <= k; ++i)
                  {
                           pair<int, int> p1 = pq.top();
                           ans.push_back(p1.second);
                           pq.pop();
                  }

                  return ans;
         }
};