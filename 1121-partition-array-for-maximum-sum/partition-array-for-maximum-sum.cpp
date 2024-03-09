class Solution {
public:
    int dp[501];
    int solve(vector<int>& arr, int k, int start){
        if(start>= arr.size()){
            return 0;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        int ans = 0;
        int max_elem = 0;
        int end = min((int)arr.size(), start+k);
        for(int i=start;i<end;i++){
            max_elem = max(max_elem, arr[i]);
            ans = max(ans, max_elem * (i-start+1) + solve(arr, k, i+1));
        }
        return dp[start] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, k, 0);
    }
};