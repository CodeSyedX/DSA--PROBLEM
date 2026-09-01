class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int jump = 0;
    while(right < nums.size()-1){
        int fas = 0;
        for(int i =left ; i <= right;i++){
             fas =  max(fas, i + nums[i]);
        }
        left = right +1;
        right = fas;
        jump++;
    }
    return jump;
    }
};