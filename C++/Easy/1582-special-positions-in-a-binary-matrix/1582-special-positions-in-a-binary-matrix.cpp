class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt= 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>temp(1, vector<int>(n ,0));
        vector<vector<int>>temp2(m, vector<int>(1 ,0));
        for(int i = 0; i < m ; i++){
            for(int j =0 ; j < n ; j++){
                if(mat[i][j] == 1) 
                {temp[0][j] += 1;
                temp2[i][0] += 1;
                }
            }
        }
        for( int i = 0 ; i < m ; i++){
            for(int j = 0 ; j <  n ; j++){

                           if(  mat[i][j] == 1 && temp[0][j] == 1 && temp2[i][0] == 1) cnt++;
            }
            
        }
        return cnt;
        
    }
};