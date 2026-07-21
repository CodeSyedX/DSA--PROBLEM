class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int>ans;
        while(left <= right){
            int res = 0;
            int temp = left;          
            bool isValid = true;
            while(temp >0){
             
                res = temp%10;
           
                if( res == 0 || left %  res != 0){
                  isValid = false;
                    break;
                   
                }
                
                temp = temp/10;
                
            }
          if(isValid == true) ans.push_back(left);
          left++;
        }
        return ans;
    }
};