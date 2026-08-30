class Solution {
public:
int f( int ind , vector<int> & nums , vector<int> & dp ){
    int n = nums.size();
    
    if(ind < 0 ) return 0;
    if(ind == 0) return dp[0] =  nums[ind];
    if (dp[ind] != -1) return dp[ind];
    int pick = nums[ind] + f(ind-2 , nums, dp);
    int not_pick = 0 + f(ind-1, nums, dp);
    return dp[ind] = max(pick , not_pick);

}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n== 1) return nums[0];
        if(n== 0) return 0;
       vector<int> dp1(n, -1), dp2(n, -1);
        vector<int> firstRange, lastRange;
        
        for(int i = 0; i < n; i++) {
            if(i != n - 1) firstRange.push_back(nums[i]);
            if(i != 0) lastRange.push_back(nums[i]);
        }

        return max(f(n - 2, firstRange, dp1), f(n - 2, lastRange, dp2));
    }
};