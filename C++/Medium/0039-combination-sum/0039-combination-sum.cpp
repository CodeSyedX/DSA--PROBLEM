class Solution {
public:
 void comb(int index , int n , int target , vector<int>& candidates, vector<int>&ans,vector<vector<int>>& res  ){
         if(index == n){
            if(target == 0){
                res.push_back(ans);
                
            }
            return ;
         }

         if(candidates[index] <= target){
            ans.push_back(candidates[index]);
           comb(index , n , target- candidates[index] , candidates, ans, res);
            ans.pop_back();
         }
          comb(index+1 , n , target , candidates, ans, res);
 }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>> res;
        int n = candidates.size();
          comb(0 , n , target , candidates, ans, res);
          return res;
        
    }
};