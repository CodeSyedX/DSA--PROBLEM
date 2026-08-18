class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
       int first = 0;;
       for( int i = 1 ; i < n ; i++){
        if(nums[i] != nums[first]){
            first ++;
          nums[first] = nums[i];
        }
       }
       return first+1;

      
    }
};