class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        int tim= 0;

        queue<pair<pair<int , int>, int>>q;
        vector<vector<int>>vis(m , vector<int>(n ,0));
        for( int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j }, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int drow[4] = { -1, 0 , 1, 0};
        int dcol[4] =  { 0 , 1,  0 , -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
             tim = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n  && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol} , tim+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i = 0; i < m;i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) return -1;
               
            }
        }
        return tim;
    }
};