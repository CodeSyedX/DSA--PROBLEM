#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    // Suffix sum of the absolute values of all negative elements
    vector<long long> suff(n + 2, 0);
    for (int i = n; i >= 1; --i) {
        suff[i] = suff[i + 1] + (a[i] < 0 ? -a[i] : 0);
    }
    
    // Base case: K = 0 (No operations applied)
    long long min_cost = suff[1];
    int best_K = 0;
    
    // Find optimal boundary K where a[K] > 0
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 0) {
            long long cost = a[i] + suff[i + 1];
            if (cost < min_cost) {
                min_cost = cost;
                best_K = i;
            }
        }
    }
    
    // Populate the ideal flip states
    vector<int> f(n + 2, 0);
    if (best_K > 0) {
        f[best_K] = 1;
    }
    for (int i = 1; i < best_K; ++i) {
        if (a[i] < 0) {
            f[i] = 1;
        }
    }
    
    // Determine the required operation indices Set 'S'
    vector<int> S;
    for (int i = 1; i <= n; ++i) {
        if (f[i] != f[i + 1]) {
            S.push_back(i);
        }
    }
    
    // Process S in descending order to assemble a strictly valid sequence
    reverse(S.begin(), S.end());
    
    int head = -1;
    vector<int> next_node(n + 1, -1);
    
    for (int x : S) {
        if (a[x] > 0) {
            // Prepend: 0 Larger elements processed before x
            next_node[x] = head;
            head = x;
        } else {
            // Insert at index 1: 1 Larger element processed before x
            next_node[x] = next_node[head];
            next_node[head] = x;
        }
    }
    
    // Translate the linked list sequence back to an array
    vector<int> ans;
    int curr = head;
    while (curr != -1) {
        ans.push_back(curr);
        curr = next_node[curr];
    }
    
    // Output the count and the ordered operations
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
} change the variable of  all the code to some unusual plagirism so it passes the plagerism and my code is the most  unique one