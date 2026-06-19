/*ount Occurrences in Sorted Array


11

Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Examples
Example 1:
Input:
 N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output
: 4
Explanation:
 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input:
 N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output
: 5
Explanation:
 2 is occurring 5 times in the given array so it is our answer.*/

 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans = {-1, -1};
        if(nums.size()<1){
            return ans;
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                ans[0] = i;
                break;
            }
        }
        for(int i = ans[0]; i<nums.size(); i++){
            if(nums[i]==target){
                ans[1]=i;
            }
        }

        return ans;
        
    }
};
