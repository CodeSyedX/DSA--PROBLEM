/*Two Sum : Check if a pair with given sum exists in Array


44

Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Examples*/

// Hashing 

#include<bits/stdc++.h>
using namespace std;

string read(vector<int> a, int target){
    map<int ,int>mpp;
    int n = a.size();
    
    for(int i = 0; i < n ; i++){
     int x = nums[i];
     int more = target - x;
     if(mpp.find(more) != mpp.end())
      return "YES"
        mpp[a] = i;
    }
    return "NO";
}








string read(int n, vector<int> book, int target)
{

int left = 0, right = n-1;
sort(book.begin(), book.end());
while(left < right) {
int sum = book[left] + book[right] ;
if(sum == target) {

return "YES";
}
else if(sum < target) left++;
else right --;
}
return "NO";

}