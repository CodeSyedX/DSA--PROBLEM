class Solution {
public:
    string say(string ans) {
        if (ans.empty()) return "1";
        string s = "";
        
        for (int i = 0; i < ans.size(); i++) {
            int cnt = 1;
            // Advance 'i' while adjacent characters are identical
            while (i < ans.size() - 1 && ans[i] == ans[i + 1]) {
                cnt++;
                i++;
            }
            s += to_string(cnt) + ans[i];
        }
        return s;
    }

    string countAndSay(int n) {
        string ans = "1";
        // Since base case n=1 is "1", run transformation n-1 times
        for (int i = 1; i < n; i++) {
            ans = say(ans);
        }
        return ans;
    }
};