class Solution {
public:
   vector<int>findpse(vector<int>& arr){
    int n = arr.size();
     
        vector<int> ans(n);
        stack<int>st;
        for( int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ans[i] = !st.empty() ? st.top(): -1;
            st.push(i);
          
        }
          return ans;
      
   }
   vector<int>findnse(vector<int>& arr){
    int n = arr.size();
        
     
        vector<int> ans(n);
 
        stack<int> st;
        
      
        for(int i = n - 1; i >= 0; i--) {
            
         
            int currEle = arr[i];
            
         
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
        
            ans[i] = !st.empty() ? st.top() : n;
            
         
            st.push(i);
        }
        
    
        return ans;

   }
    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse = findpse(arr);
    vector<int> nse = findnse(arr);
    
    int mod = 1e9 + 7;
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        
        long long count = (left * right) % mod;
        total = (total + (count * arr[i]) % mod) % mod;
    }
    
    return total;
}
};