/*
Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
*/
class TimeMap
{

         unordered_map<string, vector<pair<int, string>>> m;

public:
         TimeMap()
         {
         }

         void set(string key, string value, int timestamp)
         {
                  pair<int, string> p{timestamp, value};
                  if (m.find(key) == m.end())
                  {
                           vector<pair<int, string>> v;
                           v.emplace_back(p);
                           m.insert(make_pair(key, v));
                  }
                  else
                  {
                           m[key].emplace_back(p);
                  }
         }

         string get(string key, int timestamp)
         {
                  if (m.find(key) == m.end())
                  {
                           return "";
                  }
                  else
                  {
                           auto it = upper_bound(m[key].begin(), m[key].end(), pair<int, string>{timestamp, ""}, [](const pair<int, string> &a, const pair<int, string> &b)
                                                 { return a.first < b.first; });

                           return it == m[key].begin() ? "" : prev(it)->second;
                  }
         }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */