class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int k = 0;
        int j = 0;
        for(int i = 0 ;i < n;i++){
            if(nums[i] == 0 ) i = k;
            break;
        }
        while(j < n){
            if(nums[j] != 0){
                swap(nums[k], nums[j]);
                k++;
            }
            j++;
        }
        return;
    }
};


