#define ll long long
class Solution {
public:
    ll solve(ll mid, ll n){
        return n>=mid*1ll*(mid+1)/2;
    }
    int arrangeCoins(int n) {
        ll low=1, high = n;
        ll ans = 1;
        while(low<=high){
            ll mid = low + (high-low)/2;
            if(solve(mid, n)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};