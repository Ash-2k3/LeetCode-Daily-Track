/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

class Solution
{

public:
         int trap(vector<int> &height)
         {
                  vector<int> maxLeftSoFar(height), maxRightSoFar(height);

                  // get left height so far for blocks ready
                  for (int i = 1; i < size(height); i++)
                  {
                           maxLeftSoFar[i] = max(maxLeftSoFar[i - 1], height[i - 1]);
                  }

                  // get right height so far ready
                  for (int i = size(height) - 2; i >= 0; i--)
                  {

                           maxRightSoFar[i] = max(maxRightSoFar[i + 1], height[i + 1]);
                  }

                  int waterTrapped = 0;
                  for (int i = 0; i < size(height); i++)
                  {
                           int trap = min(maxRightSoFar[i], maxLeftSoFar[i]) - height[i];
                           waterTrapped += (trap > 0) ? trap : 0;
                  }
                  return waterTrapped;
         }
};