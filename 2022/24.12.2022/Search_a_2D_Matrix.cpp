/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

class Solution
{
public:
         bool searchMatrix(vector<vector<int>> &matrix, int target)
         {
                  int size = matrix[0].size() - 1;
                  for (int i = 0; i < matrix.size(); i++)
                  {
                           int minInRow = matrix[i][0], maxInRow = matrix[i][size];
                           if (minInRow <= target and maxInRow >= target)
                           {
                                    bool isTargetThere = binary_search(matrix[i].begin(), matrix[i].end(), target);
                                    return isTargetThere;
                           }
                           else
                           {
                                    continue;
                           }
                  }
                  return false;
         }
};
