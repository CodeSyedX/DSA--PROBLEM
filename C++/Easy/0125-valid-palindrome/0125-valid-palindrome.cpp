class Solution {
public:
    bool isPalindrome(string s) {
     string str = "";
     for( char t : s){
        if(isalnum(t)){
            str+= tolower(t);

        }
     }
        int i = 0;
        int j = str.size()-1;
        while(i <= j){
            if(str[i] != str[j]) return false;
            i++;
            j--;

        }
        return true;
    }
};