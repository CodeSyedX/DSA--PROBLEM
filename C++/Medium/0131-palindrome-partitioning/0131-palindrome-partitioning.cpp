class Solution {
public:
  bool palin(string s){
    int i =0;
    int j = s.size()-1;
    while(i<=j){
        if(s[i] != s[j])return false;
        i++;
        j--;

    }
    return true;
  }
    void partition(int index , string str, vector<string>& ans, vector<vector<string>>&res){
        if(index == str.size()){
            res.push_back(ans);
            return ;
        }
        string s = "";
        for(int i = index; i <str.size(); i++){
            s+=str[i];
            if(palin(s) == true){
             ans.push_back(s);
            partition(i+1,str, ans , res );
            ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        
        vector<string>ans;
        partition(0,s, ans,res);
        return res;


        
    }
};