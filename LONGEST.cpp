/*Length of the longest subarray with zero Sum


16

Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Examples
Example 1:
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result:
 5  
Explanation:
 The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.

Example 2:
Input:
 N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}  
Result:
 8  
Explanation:
 Subarrays with sum zero:
- {-2, 2}
- {-8, 1, 7}
- {-2, 2, -8, 1, 7}
- {6, -2, 2, -8, 1, 7, 4, -10}
The length of the longest subarray with sum zero is 8.*/

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a,
long long k) {
map<long long, int> preSumMap;
long long sum = 0;
int maxLen = 0;
for(int i= 0;i<a.size();i++) {
sum += a[i];
if(sum == k) {
maxLen = max(maxLen, i+1);

int rem = sum - k;
if(preSumMap.find(rem) != preSumMap.end())
int len = i - preSumMap[rem] ;
maxLen = max(maxLen, len);

if(preSumMap.find(sum) == preSumMap.end())
preSumMap[sum] = i;

}
}

return maxLen;

}


/*
  FOR POSITIVE AND  ZERO NUMBER ONLY */

  #include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a,
long long k) {
int left = 0, right = 0;
long long sum = a[0];
int maxLen = 0;
int n = a.size();
while(right < n) {
while(left <= right && sum > k) {
sum -= a[left] ;
left++;
}
if(sum == k) {
maxLen = max(maxLen, right - left + 1);
}
right++;
if(right < n) sum += a[right];
}

return maxLen;

}

