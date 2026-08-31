class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        if (n == 1) {
            return 1;
        }
        queue<pair< int , pair < int , int >>> q;
        vector < vector < int >> dist(n , vector<int> (m, 1e9 ));
        dist[0][0] = 1;
        q.push({1,{0,0}});
        int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
           int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for( int i = 0 ;i < 8 ; i++){
                int row = r+dx[i];
                int col = c+ dy[i];
                if(row >= 0 && row < n && col >= 0  && col < m && grid[row][col] == 0 && dis + 1 < dist[row][col]){
                    dist[row][col] = dis + 1;
                    if(row == n-1 && col == m-1) return  dis + 1;
                    q.push({dis+1 , {row, col}});
                }
            }
        }

    return -1;
     





        
    }
};