class Solution {
public:
    set<int> st;
    int dp[3001][3001];
    int solve(int i, int j, string &source, string &pattern){
        if(i==source.size()){
            if(j==pattern.size()){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        // leave
        int ans = solve(i+1, j,source, pattern);
        //matches
        if(source[i] == pattern[j]){
            ans = max(ans, solve(i+1, j+1, source, pattern));
        }
        if(st.count(i)){
            ans = max(ans, 1+ solve(i+1, j, source, pattern));
        }
        return dp[i][j] = ans;

    }
    int maxRemovals(string &source, string &pattern, vector<int>& targetIndices) {
        memset(dp, -1, sizeof(dp));
        for(auto it: targetIndices){
            st.insert(it);
        }
        return solve(0,0,source, pattern );
    }
};