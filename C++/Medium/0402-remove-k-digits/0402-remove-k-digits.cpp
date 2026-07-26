class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.length();

        if( n == k ){
            return "0";
        }

        stack<char> st;
        int i = 0;
        string ans;
        while(  i<n ){

            while( !st.empty() && num[i] < st.top() ){

                if( k > 0 ){
                    k--;
                    st.pop();
                }else{
                    break;
                }

            }

            st.push(num[i]);
            i++;

        }
        
        
        while( !st.empty() && k>0 ){
            st.pop();
            k--;
        }

        while( !st.empty() ){

            ans += st.top();
            st.pop();

        }

        reverse(ans.begin(),ans.end());

        while(ans[0] == '0' && ans != "0"){
            ans.erase(0,1);
        }

        return ans;
    }
};