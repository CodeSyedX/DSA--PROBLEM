class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     vector<int> temp = nums1;
       temp.insert(temp.end(), nums2.begin(), nums2.end());
        
   
        sort(temp.begin() , temp.end());
        int n = temp.size();
        if(n%2 == 0){
          return (double)(temp[n / 2 - 1] + temp[n / 2]) / 2.0;

        }
        else{
         return (double)temp[n / 2];
        }

        
    }
};