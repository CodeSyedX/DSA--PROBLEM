/*
169. Majority Element
Solved
Easy
Topics
premium lock icon
Companies
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.
 

Follow-up: Could you solve the problem in linear time and in O(1) space?


*/

//  Morre -  vOTE ALGORITHM
#include<iostream>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
       int cnt = 0;
       int el ;
       for(int i = 0 ; i < n ; i++){
        if(cnt == 0){
            cnt = 1;
           el = nums[i];
        }
        else if(nums[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
       }
       int cnt1= 0;
       for(int i = 0 ; i < n ; i ++){
        if(nums[i] == el) cnt1++;
       }
       if(cnt1 > n/2) return el;
       return -1;
        
    }
};


/*
Approach 2: Hash Map
Intuition:
The intuition behind using a hash map is to count the occurrences of each element in the array and then identify the element that occurs more than n/2 times. By storing the counts in a hash map, we can efficiently keep track of the occurrences of each element.

Explanation:

The code begins by initializing a hash map m to store the count of occurrences of each element.
It then iterates through the array nums using a for loop.
For each element nums[i], it increments its count in the hash map m by using the line m[nums[i]]++;.
If nums[i] is encountered for the first time, it will be added to the hash map with a count of 1.
If nums[i] has been encountered before, its count in the hash map will be incremented by 1.
After counting the occurrences of each element, the code updates n to be n/2, where n is the size of the array. This is done to check if an element occurs more than n/2 times, which is the criteria for being the majority element.
The code then iterates through the key-value pairs in the hash map using a range-based for loop.
For each key-value pair (x.first, x.second), it checks if the count x.second is greater than n.
If the count is greater than n, it means that x.first occurs more than n/2 times, so it returns x.first as the majority element.
If no majority element is found in the hash map, the code returns 0 as the default value.
Note that this will only occur if the input array nums is empty or does not have a majority element.
The time complexity of this approach is O(n) because it iterates through the array once to count the occurrences and then iterates through the hash map, which has a maximum size of the number of distinct elements in the array.

Code

*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        n = n/2;
        for(auto x: m){
            if(x.second > n){
                return x.first;
            }
        }
        return 0;
    }
};