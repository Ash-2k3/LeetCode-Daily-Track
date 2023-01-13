/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/
class Solution
{
         int findPivot(const vector<int> &nums)
         {
                  int s = 0, e = nums.size() - 1;
                  while (s < e)
                  {
                           int mid = s + (e - s) / 2;
                           if (nums[mid] >= nums[0])
                           {
                                    s = mid + 1;
                           }
                           else
                           {
                                    e = mid;
                           }
                  }
                  return s - 1;
         }

         int binarySearch(int s, int e, const vector<int> &nums, int target)
         {
                  int ans = -1;
                  while (s <= e)
                  {
                           int mid = s + (e - s) / 2;
                           if (nums[mid] == target)
                           {
                                    ans = mid;
                                    break;
                           }
                           else if (nums[mid] > target)
                           {
                                    e = mid - 1;
                           }
                           else
                           {
                                    s = mid + 1;
                           }
                  }
                  return ans;
         }

public:
         int search(vector<int> &nums, int target)
         {
                  if (nums[0] <= nums[nums.size() - 1])
                  {
                           int elementAtIndex = binarySearch(0, nums.size() - 1, nums, target);
                           return elementAtIndex;
                  }
                  int pivotIndex = findPivot(nums);
                  int elementAtIndex = -1;
                  if (target >= nums[0] and target <= nums[pivotIndex])
                  {
                           elementAtIndex = binarySearch(0, pivotIndex, nums, target);
                  }
                  else
                  {
                           elementAtIndex = binarySearch(pivotIndex + 1, nums.size() - 1, nums, target);
                  }
                  cout << pivotIndex << endl;
                  return elementAtIndex;
         }
};