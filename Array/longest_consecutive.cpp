

/*
Blog
Discussion
Logo
Solve

LogoEditorial
Longest Consecutive Sequence in an Array


13

Problem Statement: Given an array nums of n integers.

Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Examples
Example 1:
Input:
 nums = [100, 4, 200, 1, 3, 2]  
Output:
 4  
Explanation:
 The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

Example 2:
Input:
 nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]  
Output:
 9  
Explanation:
 The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.
*/


#include<bits/stdc++.h>
using namespace std;

int longest(vector<int>nums){
    int n = nums.size();
    if (n== 0 ) return 0;
    int cnt =0;
    int small = INT_MIN;
    int l = 1;
    int small = nums[0];
    for(int i = 0 ; i < n ; i ++){
        if( nums[i]-1 == small){
            cnt++;
            smalll = nums[i]
        }
        else if(nums[i]-1 != small ){
            cnt = 1;
            small = nums[i];
        }
        l = max(l, cnt);

    }
    return l;
}




#include<bits/stdc++.h>
using namespace std;

int longest(vector<int>nums){
    int n = nums.size();
    if (n== 0 ) return 0;
    int cnt =0;
    int small = INT_MIN;
    int l = 1;
    unordered_set<int>st;
    for(int i = 0 ; i < n ; i++){
       st.insert(nums[i]) ;
    }
    for( auti it: st){
        if(st.find(it-1) == st.end()){
            cnt = 1;
            int x = it;
            while(st.find(it+1) == st.end()){
                cnt +=1;
                x = x+1;
            }
            l = max(l, cnt);
        }
        
    }
   
   
    return l;
}



