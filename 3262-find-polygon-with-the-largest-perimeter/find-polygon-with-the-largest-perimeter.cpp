#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ll n = nums.size();
        sort(nums.begin(),nums.end());
        vector<ll> pref(n,0);
        pref[0] = nums[0];
        for(ll i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        while(n>1&& nums[n-1]>=pref[n-2]){
            n--;
        }
        if(n>2) return pref[n-1];
        return -1;
    }
};