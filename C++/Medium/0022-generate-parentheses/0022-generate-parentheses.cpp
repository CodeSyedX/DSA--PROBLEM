class Solution {
    private:
    void dfs(int openN , int closeN, int n , string s, vector<string>& res ){
        if(openN == closeN && openN + closeN == 2 * n){
            res.push_back(s);
            return ;
        }
        if(openN < n){
            dfs(openN+ 1, closeN , n , s+"(", res);
        }
        if(closeN < openN){
            dfs(openN  , closeN +1 , n , s+")" , res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        dfs(0 , 0 , n , "" , r);
        return r;
        
    }
};