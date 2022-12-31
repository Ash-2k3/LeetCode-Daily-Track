/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

*/

class Solution
{
public:
         vector<int> productExceptSelf(vector<int> &nums)
         {
                  const int length = nums.size();
                  vector<int> prefix(length), suffix(length), ans(length);
                  prefix[0] = 1;
                  suffix[length - 1] = 1;

                  // Get Prefix Ready
                  for (int i = 1; i < length; i++)
                  {
                           prefix[i] = prefix[i - 1] * nums[i - 1];
                  }

                  // Get Suffix Ready
                  for (int i = length - 2; i >= 0; i--)
                  {
                           suffix[i] = suffix[i + 1] * nums[i + 1];
                  }

                  for (int i = 0; i < length; i++)
                  {
                           ans[i] = prefix[i] * suffix[i];
                  }
                  return ans;
         }
         
};