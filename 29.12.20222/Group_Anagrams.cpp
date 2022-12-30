/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/
class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> map ;
        for(auto i : strs){
            string s = i ;
            sort(s.begin() , s.end());
            map[s].push_back(i);
        }
        for(auto &i:map){
            ans.push_back(i.second);
        }
        return ans ;
    }
};