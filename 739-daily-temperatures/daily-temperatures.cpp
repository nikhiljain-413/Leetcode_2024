class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);
        stack<int> st;
        // st.push(0);
        for(int i=0;i<n;i++){
            while(!st.empty()&&temp[i]>temp[st.top()]){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        while(st.empty()){
            ans[st.top()] = 0;
            st.pop();
        }
        return ans;
    }
};