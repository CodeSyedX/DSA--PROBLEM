class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0 ;
        int maxi = 0;
       for(char c: s){
        if(c == '('){
            mini++;
            maxi++;
        }
        else if(c == ')'){
            if(mini >0) mini--;
            maxi--;
        }
        else{
            if(mini >0) mini--;
            maxi++;
          if (maxi < 0) return false;
        }
          if (maxi < 0) return false;
       }
       return  mini == 0;
    }
};