class Solution {
public:
    int sol(int ind, vector<int>&nums , vector<int>&dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return   dp[ind];
        int pick = nums[ind] + sol(ind-2, nums, dp);
        int not_pick = sol(ind-1, nums, dp);
       return  dp[ind] = max(pick, not_pick);
       

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, 0);
        dp[0] = nums[0];
        for(int ind = 1; ind < n ;ind++){
            
           int pick = nums[ind];
           if(ind -2 >= 0){
             pick+= dp[ind-2];
           } 

             int not_pick = dp[ind-1];
             dp[ind]  = max(pick , not_pick);

        }
        return dp[n-1];
    }
};