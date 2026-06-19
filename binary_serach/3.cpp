/*What is Upper Bound?
The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.

Examples
Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] > x.

Example 2:
Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
Result: 4
Explanation: Index 4 is the smallest index such that arr[4] > x.
            */


#include<iostream>
using namespace std;

class Solution{
    public:
    int answer(vector<int>nums, int target){
        int n = nums.size();
        int low = 0;
        int high  = n-1;
        int ans = n;
        while(low <= high){
            int mid  = low +(high-low)/2
            if(nums[mid] >= target) {
                ans = mid;
                high = mid-1;}
            else{
                low = mid+1;

            }    
            
return ans;
                       
        }
    }
    

    
};            