class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) {
            return -1;
        }

        // Special case: 1x1 matrix with clear cell
        if (n == 1 && m == 1) {
            return 1;
        }
    vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<pair<int , pair<int , int>>>q;
        q.push({1, {0 , 0}});
        dis[0][0] = 1;
       
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int wt = it.first;
            int row = it.second.first;
            int col = it.second.second;
           for( int i = -1 ; i <= 1; i++){
            for(int j = -1 ; j <= 1; j++){
                      int nrow = row + i;
                int ncol = col + j;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && wt +1 < dis[nrow][ncol]){
                    if(nrow == n-1 && ncol == m-1) return wt + 1;
                    dis[nrow][ncol] = wt + 1;
                    q.push({dis[nrow][ncol], {nrow, ncol}});
                }
           
            }
           }
        }      
        return -1;
    }
};