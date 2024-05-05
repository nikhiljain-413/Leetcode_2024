class Solution {
public:
    bool solve(vector<vector<int>> &dp, int len, int n){
        // if(len == n) return true;
        vector<int> temp(26,0);
        for(int i=0;i<26;i++){
            temp[i] = dp[len-1][i];
        }
        for(int i=2*len-1;i<n;i+=len){
            for(int j=0;j<26;j++){
                if(dp[i][j] - dp[i-len][j] != temp[j]) return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int> (26,0));
        for(int i=0;i<n;i++){
            dp[i][s[i]-'a'] = 1;
        }
        for(int j=0;j<26;j++){
            for(int i=1;i<n;i++){
                dp[i][j]+= dp[i-1][j];
            }
        }
        vector<int> possible;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                possible.push_back(i);
            }
        }
        // cout<<n<<" "<<solve(dp, 15, n)<<endl;
        for(auto poss: possible) if(solve(dp, poss, n)) return poss;
        return n;
    }
};
// 1 5
// 3