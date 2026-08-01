class Solution {
public:
bool check(string str){
    int i = 0;
    int j = str.size()-1;
    while(i <=j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}
 void eval(string s , int index, vector<string>& res,  vector<vector<string>>& ans){
    if (index == s.size()) {
            ans.push_back(res);
            return;
        }
          string str = "";
          for(int i = index ; i < s.size(); i++){
            str+=s[i];
            if(check(str) == true){
                res.push_back(str);           
                eval(s, i + 1, res, ans);      
                res.pop_back();
            }
          }

          return;

      
       
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;
        vector<string> res;

     
        eval(s, 0, res, ans);
        
        return ans;
    }
};