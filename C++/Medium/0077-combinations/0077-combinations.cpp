class Solution {
public:
   void calculate(int start , int n , int k , vector<vector<int>>& ans , vector<int>& res){
    if(res.size() == k){
        ans.push_back(res);
        return ;
    }
    for(int i = start ; i <=n ;i++){
         
            res.push_back(i) ;     
            calculate(i + 1, n, k , ans , res); 
            res.pop_back();
            
            

    }
   }
    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
         vector<vector<int>> ans;
         calculate(1 , n , k , ans, res);
         return ans;
        
    }
};