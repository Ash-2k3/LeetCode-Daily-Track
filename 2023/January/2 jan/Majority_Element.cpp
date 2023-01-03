/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> map ;
        for(const auto &i : nums){
            map[i]++ ;
        }
        int maxf = -1 , ans = -1 ;
        for(auto &i : map){
            if(i.second>maxf){
                maxf = i.second ;
                ans = i.first ;
            }
        }
        return ans ;
    }
};

/* Follow Up
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currentNum = nums[0] , life = 1 ;
        for(int i = 1 ; i<size(nums) ; i++){
            if(life == 0){
                currentNum = nums[i];
            }
            if(nums[i] == currentNum){
                life++ ;
            }else{
                life-- ;
            }
        }
        return currentNum ;
    }
};
*/

