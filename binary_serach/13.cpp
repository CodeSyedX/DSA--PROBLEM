/*Finding Sqrt of a number using Binary Search


10

Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

Examples
Input: N = 36
Output: 6
Explanation: Square root of 36 is 6. 
Input: N = 28
Output: 5
Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5. */

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int answer(vector<int>nums int target){
        int n = nums.size();
        int low =0;
        int high = n-1;
        while(low<=high){
            long long mid = low +(high-low)/2;
            long long val = mid*mid;
            if(mid <= target){
                low = mid+1;
            }
            else high = mid-1;
        }
        return high;
    }
}