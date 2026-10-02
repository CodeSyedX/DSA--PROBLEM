class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > pq;
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
         vector<vector<int>>vis(n , vector<int>(n,1e9));
         vis[0][0] = 1;
         pq.push({1 , {0, 0}});
         while(!pq.empty()){
            auto it  = pq.top();
            int weight = it.first;
            int row = it .second.first;
            int col = it.second.second;
            pq.pop();
          if (weight > vis[row][col]) continue;
                for (int i = -1 ; i <= 1;i++){
                    for(int j = -1; j <= 1;j++){
                        if(i == 0 && j == 0 ) continue;
                        int nrow =  i+row;
                        int ncol = j+col;
                       
                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol <n && grid[nrow][ncol] == 0 && vis[nrow][ncol] > weight + 1){

                            vis[nrow][ncol] = weight + 1;
                            pq.push({vis[nrow][ncol] ,{nrow , ncol}});
                            
                        }
                    }
                
            }
         }

             return vis[n-1][n-1] == 1e9 ? -1 : vis[n-1][n-1];
        
    }
};