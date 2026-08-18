class Solution {
public:

   void dfs(int node , vector<int>adj[] , vector<int>&vec){
    vec[node] = 1;
    for( auto it : adj[node] ){
        if(!vec[it]){
            dfs(it , adj , vec);
        }
    }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i = 0; i < n ;i++){
            for(int j = 0; j < n ; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
            
                }
            }
        }
        vector<int>vec(n,0);
        int cnt = 0;
        for( int i = 0 ;i < n ; i++){
            
            if(!vec[i]){
                cnt++;
                dfs(i , adj , vec);
            }
        }
        return cnt;
    }
};