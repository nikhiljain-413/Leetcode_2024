#define ll long long
class Solution {
public:
    int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int ans = 0;
        for(int i=0;i<=n;i++){
            while(st.size() && (i==n || arr[st.top()]>=arr[i])){
                int mid = st.top();
                st.pop();
                int right = i;
                int left = (st.size())?st.top() : -1;
                ans = (ans + arr[mid]*1ll*(mid-left)*(right-mid))%MOD;
            }
            st.push(i);
        }
        return ans%MOD;
    }
};