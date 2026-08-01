class Solution {
public:
       vector<vector<int>>calculate(int start, int n , vector<int>& nums,     vector<vector<int>>& res){
        if(start == n){
            res.push_back(nums);
            return res;
        }
        for(int i = start ; i < n ; i++){
            swap(nums[start], nums[i]);
            calculate(start+1, n , nums, res);
            swap(nums[i] , nums[start]);
        }
        return res;
       }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
         vector<vector<int>>res;
         calculate(0 , n , nums, res);
         return res;
        
    }
};