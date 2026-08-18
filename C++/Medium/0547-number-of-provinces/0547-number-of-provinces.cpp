#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        // 1. Build adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        // 2. Traversal to count connected components
        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, adj, visited);
            }
        }
        return cnt;
    }
};