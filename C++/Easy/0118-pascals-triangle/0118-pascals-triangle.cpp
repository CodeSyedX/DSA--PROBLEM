class Solution {
public:
   vector<int>gen(int n){
    vector<int>ans;
    long long val = 1;
    ans.push_back(1);
    for(int i = 1; i < n ; i++){
        val = val * (n-i);
        val = val /(i);
        ans.push_back(val);

    }
    return ans;
    
   }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>final;
        for(int i = 1; i <= numRows; i++){
            final.push_back(gen(i));
        }
        return final;
        
    }
};