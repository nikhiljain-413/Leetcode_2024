int dp[301][11];
class Solution {
public:
    vector<int> jobDifficulty;
        if(d>jobDifficulty.size()-indx){
            return INT_MAX/4;
        }
        if(d==jobDifficulty.size()-indx){
            return accumulate(jobDifficulty.begin()+indx, jobDifficulty.end(),0);
        }
        if(dp[indx][d]!=-1){
            return dp[indx][d];
        }
        int ans=INT_MAX;
        int mx = jobDifficulty[indx];
        for(int i=indx;i<=min(jobDifficulty.size()-1,jobDifficulty.size()-d);i++){
            mx = max(mx,jobDifficulty[i]);
            ans = min(ans, mx + solve(i+1,d-1));
        }
        return dp[indx][d]= ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this->jobDifficulty = jobDifficulty;
        memset(dp, -1, sizeof(dp));
        int ans = solve(0,d);
        return (ans>=INT_MAX/4)?-1: ans;
    }
};