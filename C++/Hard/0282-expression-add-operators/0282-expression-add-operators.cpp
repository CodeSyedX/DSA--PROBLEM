class Solution {
public:

    void answer(string s , int target , vector<string>&ans, int index, const string& path , long eval,  long residual){
        if(index == s.size()){
            if(eval == target){
                ans.push_back(path);
                
            }
            return ;
        }

        string str = "";
        
   long num = 0;

        for(int i = index ;i <s.size();i++){
            if(i> index && s[index] == '0') return;
            str+=s[i];
            num = num*10 + s[i] -'0';
            if(index == 0){
                answer(s,target,ans,i+1,path + str , num, num);
            }
            else{
                answer(s, target , ans, i+1,path + "+" + str, eval + num, num );
                answer(s, target , ans, i+1,path + "-" + str, eval - num, -num );
                answer(s, target , ans, i+1,path + "*" + str, eval- residual + residual* num, residual*num );
            }

        }
    }
    vector<string> addOperators(string num, int target) {
             vector<string> ans;
          answer(num,target,ans, 0, "", 0, 0);
        return ans;

        
    }
};