class Solution {
public:
    bool dfs(int node,int col ,vector<int> & vis, vector<vector<int>>&adj){
        vis[node] = col;
   for(auto it : adj[node]){
    if(vis[it] == -1){
        if(dfs(it, !col ,vis, adj) == false) return false;
    }
    else if(vis[it] == col) return false;

   }
   return true;
       
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v  = graph.size();
        vector<int> vis(v, -1);
        for(int i = 0;i<v;i++){
            if(vis[i] == -1){
                if(dfs(i,0,vis,graph) == false)return false;
            }
        }
        return true;

    }
};