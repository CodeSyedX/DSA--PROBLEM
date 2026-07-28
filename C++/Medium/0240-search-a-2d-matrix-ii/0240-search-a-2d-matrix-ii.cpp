class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n  = matrix[0].size();
      
        bool ans = false;
        for(int i = 0 ; i < m ;i++){
              int low = 0;
              int high = n-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(matrix[i][mid] == target){
                    return true;
                    
                }
                else if(matrix[i][mid] > target) high = mid-1;
                else if(matrix[i][mid] < target) low = mid+1;

            }


        }
        return ans;
        
    }
};