#define ll long long
class Solution {
public:
    vector<ll> dp;
    ll solve(ll indx, string s){
        if(indx == s.size()){
            return 1;
        }
        if(dp[indx]!=-1){
            return dp[indx];
        }
        char ch = s[indx];
        ll ans = 0;
        if(ch=='0'){
            return ans;
        }
        if(ch>'0' && ch<='9'){
            ans += solve(indx+1, s);
        }
        if(indx+1<s.size()){
            string st= s.substr(indx, 2);
            if(st>="10" && st<="26"){
                ans += solve(indx+2, s);
            }
        }
        return dp[indx] = ans;
    }
    int numDecodings(string s) {
        ll n = s.size();
        dp.resize(n+1,-1);
        return solve(0, s);
    }
};