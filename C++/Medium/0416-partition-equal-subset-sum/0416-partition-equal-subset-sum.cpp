#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    /**
     * Helper function to determine if a subset exists with a given target sum.
     * Uses space-optimized Dynamic Programming.
     */
    bool canFindSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // dp[j] will be true if a sum of 'j' is possible
        vector<bool> dp(target + 1, false);

        // Base case: A sum of 0 is always possible (by picking an empty subset)
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            // Iterate backwards from target down to nums[i]
            // This ensures we use the value from the 'previous row' logic
            // and don't pick the same element multiple times for one sum.
            for (int j = target; j >= nums[i]; j--) {
                if (dp[j - nums[i]] == true) {
                    dp[j] = true;
                }
            }
            
            // Optimization: If we found the target already, we can return early
            if (dp[target]) return true;
        }

        return dp[target];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // If the total sum is odd, it's impossible to split into two equal integers
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        return canFindSubsetSum(nums, target);
    }
};