class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int nse = n;
        int pse = -1;
        int maxi = INT_MIN;
        int e = 0;
        for( int i = 0 ; i < n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                 e = st.top() ;
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxi = max(maxi , heights[e] * (nse- pse -1));

            }
            st.push(i);
        }
        while(!st.empty()){
            e = st.top();
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
             maxi = max(maxi , heights[e] * (nse- pse -1));

        }

        return maxi;
        
    }
};