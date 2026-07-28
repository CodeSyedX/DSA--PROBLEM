class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 1;
        int high = n-2;
        int ans = -1;
        while(low <= high){
            int mid = low +  (high - low)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                ans = mid ;
                break;
            }
            else if(arr[mid-1] < arr[mid]) low = mid+1;
            else   high = mid-1;
        }
        return ans;

        
    }
};