/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/
class Solution
{
public:
         int longestConsecutive(vector<int> &nums)
         {
                  unordered_set<int> set;
                  for (const auto &i : nums)
                  {
                           set.insert(i);
                  }
                  int ans = 0;
                  for (auto i : set)
                  {
                           if (set.find(--i) != set.end())
                           {
                                    cout << "here" << endl;
                                    continue;
                           }
                           i++;
                           int len = 1;
                           int num = i + 1;
                           while (set.find(num) != set.end())
                           {
                                    set.erase(num);
                                    len++;
                                    num++;
                           }
                           cout << len << endl;
                           ans = max(ans, len);
                  }
                  return ans;
         }
};