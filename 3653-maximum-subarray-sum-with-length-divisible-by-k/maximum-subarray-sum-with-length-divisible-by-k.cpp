#define ll long long
class Solution {
public:
    long long maxSubarraySum(vector<int>& nu, int k) {
        ll n = nu.size();
        vector<ll> nums(nu.begin(), nu.end());
        for(ll i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        map<ll,ll> mp;
        for(ll i=0;i<k-1;i++){
            mp[i] = nums[i];
        }
        mp[k-1] = 0;
        ll ans = -1e15;
        for(ll i=k-1;i<n;i++){
            ans = max(ans, nums[i]-mp[i%k]);
            mp[i%k] = min(mp[i%k], nums[i]);
        }
        return ans;
    }
};