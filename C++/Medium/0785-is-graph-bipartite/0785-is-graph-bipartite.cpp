class Solution {
public:

   bool dfs( int i , int col , vector<vector<int>>& graph , vector<int>& vis)
{
    vis[i] = col;
    for( auto it : graph[i]){
        if(vis[it] == -1){
            if(dfs(it, !col , graph , vis) == false) return false;
         
        }
   else if(vis[it] == col){
                return false;
            }
    }
    return true;
}    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, -1);
        for( int i = 0 ; i < n ;i++){
            if(vis[i] == -1){
                if(dfs(i , 0 , graph , vis)== false) return false;
            }
        }
        return true;
    }
};