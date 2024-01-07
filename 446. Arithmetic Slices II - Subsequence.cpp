#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        ll n = nums.size();
        vector<unordered_map<ll,ll>> v(n);
        ll ans = 0;
        for(ll i=1;i<n;i++){
            for(ll j=0;j<i;j++){
                ll diff = nums[i]*1ll-nums[j];
                v[i][diff] += 1+v[j][diff];
                ans += v[j][diff];
            }
        }
        return ans;
    }
};