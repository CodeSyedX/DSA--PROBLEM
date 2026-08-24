class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int n = numCourses;
       vector<int>adj[n];
       for(auto it:prerequisites){
        adj[it[1]].push_back(it[0]);
       }
       vector<int>indeg(n);
       for( int i =0 ; i <n ; i++){
        for(auto it : adj[i]){
            indeg[it]++;
        }
       }
       queue<int>q;
        for(int i = 0;i < n ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
          int node = q.front();
          cnt++;
          q.pop();
          for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it]==0)q.push(it);
          }
        }
        if(cnt == n) return true;

        return false;
    }
};