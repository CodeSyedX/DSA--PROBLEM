class Solution {
public:

int f(int ind, vector<int> & nums , vector<int> & dp){
    if(ind == 0 ) return nums[ind];
    if( ind < 0 ) return 0;
    if(dp[ind] != -1) return dp[ind];
    int pick = nums[ind] + f(ind-2,nums ,dp);
    int not_pick = 0 + f(ind-1, nums , dp);
    return  dp[ind] = max(pick , not_pick );
}

    int rob(vector<int>& nums) {
      
        int n = nums.size();
        vector<int> dp(n, -1);
        if(n < 0 ) return 0 ;
        if(n == 1) return nums[0];
        
       
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        for( int i = 2 ; i < n ; i ++){
             
              int pick = nums[i] + prev2;
              int not_pick = 0 + prev;
              int cur = max(pick, not_pick) ;
              prev2 = prev;
              prev = cur;
        }
        return prev;
        
    }
};