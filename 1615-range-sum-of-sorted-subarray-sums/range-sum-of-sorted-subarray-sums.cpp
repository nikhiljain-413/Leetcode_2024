const int MOD = 1e9+7;
#define ll long long
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<ll> temp;
        for(ll i=0;i<n;i++){
            ll sum = 0;
            for(ll j=i;j<n;j++){
                sum+=nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin(), temp.end());
        ll ans = 0;
        for(ll i=left-1;i<right;i++){
            ans = (ans + temp[i])%MOD;
        }
        return ans;
    }
};