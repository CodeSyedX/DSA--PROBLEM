class Solution {
public:
   int solve(int i , int j , vector<vector<int>>&triangle , vector<vector<int>>& dp){
    int n = triangle.size();
    if(i == n-1){
        return triangle[n-1][j];
    }
    if(dp[i][j] != 1e9 ) return dp[i][j];
    int d = triangle[i][j] + solve(i+1 , j, triangle , dp);
    int dg = triangle[i][j] + solve(i+1, j+1 , triangle , dp);
      return  dp[i][j] = min(d, dg);
   }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        if(n == 1 ) return triangle[0][0];
        vector<vector<int>>dp(n , vector<int>(n , 1e9));
        for( int i = 0 ; i < n ; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = i ; j >= 0; j--){
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
};