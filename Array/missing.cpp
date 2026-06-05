/*Find the Missing Number
Last Updated : 19 Apr, 2025
Given an array arr[] of size n-1
 with distinct integers in the range of [1, n]. This array represents a
  permutation of the integers from 1 to n with one element missing. 
  Find the missing element in the array.*/

#include <iostream>
#include <vector>
using namespace std;

int missingNum(vector<int> &arr) {
    int n = arr.size() + 1;
  
    // Calculate the sum of array elements
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }

    // Calculate the expected sum
    long long expSum = (n *1LL* (n + 1)) / 2;  

    // Return the missing number
    return expSum - sum;
}

int main() {
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1};  
    cout << missingNum(arr);  
    return 0;
}