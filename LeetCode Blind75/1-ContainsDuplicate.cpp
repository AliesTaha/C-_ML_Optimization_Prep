/*
Given an integer array nums, return true if any value appears at least twice 
in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.
Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.
Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(&nums[0], &nums[nums.size()]);
        if (nums.size()<=1) return false;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};

//Or another way 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> maset;
        for (int i=0; i<nums.size(); i++) {
            if (maset.find(nums[i])!=maset.end())
                return true;
            maset.insert(nums[i]);
        }
        return false;
    }
};

