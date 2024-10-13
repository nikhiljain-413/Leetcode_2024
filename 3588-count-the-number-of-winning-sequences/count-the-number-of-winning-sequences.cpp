#define ll long long

class Solution {
public:
    map<char,ll> mp;
    ll MOD = 1e9+7;
    ll n;
    ll solve(string &s, ll indx, ll last, ll cnt, vector<vector<vector<ll>>> &dp){
        if(indx == s.size()){
            return cnt>n?1:0;
        }
        if(dp[indx][cnt][last]!=-1) return dp[indx][cnt][last];
        ll curr = mp[s[indx]];
        ll ans = 0;
        if(curr == 0){
            if(last!=0) ans += solve(s, indx+1, 0, cnt, dp)%MOD;
            if(last!=1) ans += solve(s, indx+1, 1, cnt+1, dp)%MOD;
            if(last!=2) ans += solve(s, indx+1, 2, cnt-1, dp)%MOD;
        }else if(curr == 1){
            if(last!=0) ans += solve(s, indx+1, 0, cnt-1, dp)%MOD;
            if(last!=1) ans += solve(s, indx+1, 1, cnt, dp)%MOD;
            if(last!=2) ans += solve(s, indx+1, 2, cnt+1, dp)%MOD;
        }else{
            if(last!=0) ans += solve(s, indx+1, 0, cnt+1, dp)%MOD;
            if(last!=1) ans += solve(s, indx+1, 1, cnt-1, dp)%MOD;
            if(last!=2) ans += solve(s, indx+1, 2, cnt, dp)%MOD;
        }
        return dp[indx][cnt][last] = ans%MOD;
    }
    int countWinningSequences(string s) {
        // f e f 0 2 0
        // w f w 1 0 1
        // e w e 2 1 2
        n = s.size();
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(2*n,vector<ll> (4,-1)));
        // memset(dp, -1, sizeof(dp));
        mp['F'] = 0;
        mp['W'] = 1;
        mp['E'] = 2;
        return solve(s, 0, 3,n, dp);
    }
};