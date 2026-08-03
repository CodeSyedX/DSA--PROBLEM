
class Solution {
public:

    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = -1;
        int maxR = grid.size();
        int maxC = grid[0].size();
        while(true) {
            bool updated = false;
            vector<vector<int>> next = grid; // COPY GRID FOR NEXT MIN

            for (int row = 0; row < maxR; row++) { // iterate over every cell. O(N) [# of rows]
                for (int col = 0; col < maxC; col++) { // O (M) [# of cols]
                    if (grid[row][col] != 2) continue; // if not rotten skip.

                    for (const auto& [x, y] : dirs) { // check all dirs for fresh orange
                        // check if out of bounds
                        int nx = col + x;
                        int ny = row + y;
                        if (nx >= grid[0].size() || nx < 0) continue;
                        if (ny >= grid.size() || ny < 0) continue;
                        

                        if (grid[ny][nx] == 1) { // yay spoil that.
                            updated = true;
                            next[ny][nx] = 2; // Update the next minutes grid
                        }
                    }
                }
            }
            grid = next;
            minutes++;
            if (!updated) break; // there was nothing changed. so theres no oranges to spoil.
            // if not changed, it will exit.
        }
        bool has = false;
        for (const auto& row : grid) {
            for (int col : row) {
                if (col == 1) has = true;
            }
        }
        if (has) return -1;
        return minutes;
    }
};
