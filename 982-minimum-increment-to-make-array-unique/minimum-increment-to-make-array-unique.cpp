#define ll long long
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<ll,ll> mp;
        for(auto num: nums){
            mp[num]++;
        }
        ll ans = 0;
        for(auto it: mp){
            ll key = it.first;
            ll value = it.second;
            if(value>1){
                mp[key+1]+=value-1;
                ans += value-1;
            }
            // cout<<ans<<endl;
            if(mp.upper_bound(key+1)==mp.end()){
                ans += (mp[key+1] + key)*1ll*(mp[key+1] + key+1)/2 - (key*1ll*(key+1)/2) - mp[key+1]*1ll*(key+1);
                // cout<<ans<<endl;
                break;
            }
        }
        return ans;
    }
};
