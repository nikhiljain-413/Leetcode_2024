#define ll long long
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k== 0 || k==1) return 0;
        ll j = 0;
        ll n = nums.size();
        ll pod = 1;
        ll ans = 0;
        for(ll i=0;i<n;i++){
            pod*=nums[i];
            while(pod>=k){
                pod/=nums[j];
                j++;
            }
            ans += (i-j)+1;
        }
        return ans;
    }
};
// 1 2 3
