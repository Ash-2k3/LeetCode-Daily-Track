/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

// BRUTE FORCE  USING LINEAR SEARCH

class Solution
{
public:
         int minEatingSpeed(vector<int> &piles, int h)
         {
                  int maxe = -1;
                  for (int i = 0; i < piles.size(); i++)
                  {
                           maxe = max(maxe, piles[i]);
                  }

                  long int s = 1, e = maxe, ans;
                  while (s <= e)
                  {
                           long int hrs = 0;
                           for (const auto &i : piles)
                           {
                                    hrs += i / s;
                                    if (i % s != 0)
                                    {
                                             hrs++;
                                    }
                           }
                           if (hrs > h)
                           {
                                    s++;
                                    continue;
                           }
                           else
                           {
                                    ans = s;
                                    break;
                           }
                  }

                  return ans;
         }
};

// OPTIMIZED (BINARY)
class Solution
{

         bool isValid(int k, vector<int> &piles, int h)
         {
                  int hours = 0;
                  for (const auto &i : piles)
                  {
                           hours += i / k;
                           if (i % k != 0)
                           {
                                    hours++;
                           }
                           if (hours > h)
                           {
                                    return false;
                           }
                  }
                  return true;
         }

public:
         int minEatingSpeed(vector<int> &piles, int h)
         {
                  int maxe = -1;
                  for (int i = 0; i < piles.size(); i++)
                  {
                           maxe = max(maxe, piles[i]);
                  }

                  int s = 1, e = maxe, ans;
                  while (s <= e)
                  {
                           int mid = (s + e) / 2;
                           if (isValid(mid, piles, h))
                           {
                                    ans = mid;
                                    e = mid - 1;
                           }
                           else
                           {
                                    s = mid + 1;
                           }
                  }

                  return ans;
         }
};