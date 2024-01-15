#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll digits[52];
    void solve(ll no){
        if(no==0){return;}
        if(no==1){
            digits[0]++;
            return ;
        }
        if(no==2){
            digits[0]++;
            digits[1]++;
            return ;
        }
        ll msb = log2(no);
        ll cn = 1ll<<msb;
        digits[msb] += no-cn+1;
        for(ll i=0;i<msb;i++){
            digits[i] += cn/2;
        }
        solve(no-cn);
    }
    bool ispossible(ll mid,long long k, ll x){
        memset(digits, 0, sizeof(digits));
        solve(mid);
        ll sum = 0;
        for(ll i=x-1;i<52;i+=x){
            sum+=digits[i];
        }
        return sum<=k;
    }
    long long findMaximumNumber(long long k, int x) {
        ll l=1;
        ll r = 1e15;
        ll ans = 1;
        while(l<=r){
            ll mid = l+(r-l)/2;
            if(ispossible(mid, k, x)){
                ans = mid;
                l = mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};