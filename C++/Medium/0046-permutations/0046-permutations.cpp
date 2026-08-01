class Solution {
public:
    void calculate(int start, int n, vector<int>& nums, vector<vector<int>>& cal) {
        // Base Case: when start reaches the end, we've formed a complete permutation
        if (start == n) {
            cal.push_back(nums);
            return;
        }

        // Try every candidate element for the current position 'start'
        for (int i = start; i < n; i++) {
            swap(nums[start], nums[i]);       // 1. Choose: Place element at 'start'
            calculate(start + 1, n, nums, cal); // 2. Explore: Recurse for next position
            swap(nums[start], nums[i]);       // 3. Un-choose (Backtrack): Restore array
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> per;
        calculate(0, nums.size(), nums, per);
        return per;
    }
};