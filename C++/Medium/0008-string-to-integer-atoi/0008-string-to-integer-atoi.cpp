class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        long ans = 0;
        int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-'){
                sign= -1;
            }
            i++;
        }
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            ans = ans* 10 +(s[i] - '0');
            if(ans> INT_MAX && sign == -1) return INT_MIN;
            if(ans > INT_MAX && sign == 1)return INT_MAX;
            i++;
        }
        
        return ans*sign;
    }
};