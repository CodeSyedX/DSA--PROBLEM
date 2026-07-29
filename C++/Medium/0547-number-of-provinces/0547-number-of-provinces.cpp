class Solution {
public:
   void dfs(int node ,vector<int> & vis ,vector<int> ad[]  ){
         vis[node] = 1;
         for( auto it : ad[node]){
            if (!vis[it]) {
            dfs( it , vis , ad);
            }
         }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>ad[n];
        for(int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1 && i!= j){
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }
        vector<int>vis(n);
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i , vis , ad);
            }
        }
        return cnt;

    }
};