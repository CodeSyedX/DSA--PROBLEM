class Solution {
public:
    int climb(int k , int n , vector<int>& dp){
        if(k == n) return 1;
        if(k > n){
            return 0 ;
            
        }
        if(dp[k] != -1) return dp[k];
         dp[k] = climb(k+1 , n , dp) + climb(k+2, n , dp);
         return dp[k];
    }
    int climbStairs(int n) {
      vector<int>dp(n+1 , -1);
        return climb(0, n , dp);
        
    }
};