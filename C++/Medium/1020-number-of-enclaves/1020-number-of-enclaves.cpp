class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n , vector<int>(m , 0));
        queue<pair<int , int >>q;
        for(int i = 0 ; i < m ; i++){
            if(grid[0][i] == 1 && vis[0][i] == 0){
                vis[0][i] = 1;
                q.push({0,i});
            }
             if(grid[n-1][i] == 1 && vis[n-1][i] == 0){
                vis[n-1][i] = 1;
                q.push({n-1, i});
            }
        }
        for(int j = 0 ; j < n ;j++ ){
             if(grid[j][0] == 1 && vis[j][0] == 0){
                vis[j][0] = 1;
                q.push({j , 0});
             }
              if(grid[j][m-1] == 1 && vis[j][m-1] == 0){
                vis[j][m-1] = 1;
                q.push({j , m-1});
             }
        }
        int delrow[] = { -1 , 0 , 1, 0};
        int delcol[] = { 0 , 1 , 0 , -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for( int i = 0  ; i < 4 ;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >=  0 && nrow <n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && 
                vis[nrow][ncol]==0){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j <m ;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};