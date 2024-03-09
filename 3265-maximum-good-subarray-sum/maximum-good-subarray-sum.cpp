#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll> pref(n,0);
        pref[0] = nums[0];
        for(ll i=1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
        }
        ll ans = -1e15;
        map<ll, ll> mp;
        mp[nums[0]] = 0;
        for(ll i=1;i<n;i++){
            ll to_find = nums[i]+k;
            if(mp.find(to_find)!=mp.end()){
                ans = max(ans, pref[i]-mp[to_find]);
            }
            to_find = nums[i]-k;
            if(mp.find(to_find)!=mp.end()){
                ans = max(ans, pref[i]-mp[to_find]);                
            }
            
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]] = min(mp[nums[i]], pref[i-1]);
            }else{
                mp[nums[i]] = pref[i-1];
            }
            
        }
        if(ans==-1e15) return 0;
        return ans;
    }
};