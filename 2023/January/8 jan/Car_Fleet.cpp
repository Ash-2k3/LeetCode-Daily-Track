/*
There are n cars going to the same destination along a one-lane road. The destination is target miles away.

You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.


*/
class Solution
{

         struct car
         {
                  int position;
                  int speed;

                  car(int position, int speed)
                  {
                           this->position = position;
                           this->speed = speed;
                  }
         };

public:
         int carFleet(int target, vector<int> &position, vector<int> &speed)
         {
                  if (position.size() == 1)
                  {
                           return 1;
                  }
                  vector<struct car> helper;
                  for (int i = 0; i < position.size(); i++)
                  {

                           struct car a(position[i], speed[i]);
                           helper.emplace_back(a);
                  }

                  sort(helper.begin(), helper.end(), [](const struct car &p1, const struct car &p2)
                       { return p1.position > p2.position; });

                  vector<float> v;

                  for (int i = 0; i < helper.size(); i++)
                  {
                           float timeTaken = (target - helper[i].position) / static_cast<float>(helper[i].speed);
                           v.push_back(timeTaken);
                  }
                  vector<float> fleet;
                  fleet.emplace_back(v[0]);
                  for (int i = 1; i < v.size(); i++)
                  {
                           if (fleet.back() >= v[i])
                           {
                                    continue;
                           }
                           else
                           {
                                    fleet.emplace_back(v[i]);
                           }
                  }

                  return fleet.size();
         }
};