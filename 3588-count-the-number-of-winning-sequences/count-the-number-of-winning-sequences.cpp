#define ll long long

class Solution {
public:
    map<char,ll> mp;
    ll MOD = 1e9+7;
    int dp[1001][2002][4];
    ll solve(string &s, ll indx, ll last, ll cnt){
        if(indx == s.size()){
            return cnt>1000?1:0;
        }
        if(dp[indx][cnt][last]!=-1) return dp[indx][cnt][last];
        ll curr = mp[s[indx]];
        ll ans = 0;
        if(curr == 0){
            if(last!=0) ans += solve(s, indx+1, 0, cnt)%MOD;
            if(last!=1) ans += solve(s, indx+1, 1, cnt+1)%MOD;
            if(last!=2) ans += solve(s, indx+1, 2, cnt-1)%MOD;
        }else if(curr == 1){
            if(last!=0) ans += solve(s, indx+1, 0, cnt-1)%MOD;
            if(last!=1) ans += solve(s, indx+1, 1, cnt)%MOD;
            if(last!=2) ans += solve(s, indx+1, 2, cnt+1)%MOD;
        }else{
            if(last!=0) ans += solve(s, indx+1, 0, cnt+1)%MOD;
            if(last!=1) ans += solve(s, indx+1, 1, cnt-1)%MOD;
            if(last!=2) ans += solve(s, indx+1, 2, cnt)%MOD;
        }
        return dp[indx][cnt][last] = ans%MOD;
    }
    int countWinningSequences(string s) {
        // f e f 0 2 0
        // w f w 1 0 1
        // e w e 2 1 2
        memset(dp, -1, sizeof(dp));
        mp['F'] = 0;
        mp['W'] = 1;
        mp['E'] = 2;
        return solve(s, 0, 3,1000);
    }
};