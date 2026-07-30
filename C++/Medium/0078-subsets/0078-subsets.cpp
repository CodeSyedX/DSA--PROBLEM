class Solution {
    private:
     void subset(vector<int>& nums, int i , vector<int>& sub, vector<vector<int>>& main){
        main.push_back(sub);
        for(int j = i ; j < nums.size(); j++){
            sub.push_back(nums[j]);
            subset(nums, j+1 , sub , main);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>main;
        vector<int>sub;
        subset( nums, 0 , sub , main);
        return main;
        
    }
};