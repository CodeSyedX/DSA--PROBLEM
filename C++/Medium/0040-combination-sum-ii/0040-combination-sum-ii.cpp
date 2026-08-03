class Solution {
public:
   void combin(int index , int target , vector<int>&  arr , vector<vector<int>>&ans, vector<int>& res){
    if(target == 0) {
     ans.push_back(res);
     return ;
    }
    for(int i = index ; i < arr.size(); i++){
        if(i > index && arr[i] == arr[i-1] ) continue;
        if(arr[i] > target) break;
        res.push_back(arr[i]);
        combin(i +1 , target - arr[i] , arr , ans,res );
        res.pop_back();
    }
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>>ans;
        vector<int>res;
        combin(0, target , candidates, ans, res);
        return ans;
        
    }
};