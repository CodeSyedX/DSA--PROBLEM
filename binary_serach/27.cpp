/*Find the row with maximum number of 1's


10

Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

Examples
Example 1:
Input Format: n = 3, m = 3, 
mat[] = 
1 1 1
0 0 1
0 0 0
Result: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Example 2:
Input Format: n = 2, m = 2 , 
mat[] = 
0 0
0 0
Result: -1
Explanation:  The matrix does not contain any 1. So, -1 is the answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int answer(vector<int>&nums, int n, int target){
        int low = 0;
        int high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    int asn(vector<vector<int>>& mat , int n , int m){
        int maxi = 0;
        int index = -1;
        for(int i = 0 ; i < n ; i++){
            int cnt = m - answer(mat[i] , m , 1);
            if(cnt > maxi){
                maxi = cnt;
                index = i; // Fixed: was index = -1
            }
        }
        return index;
    }
};