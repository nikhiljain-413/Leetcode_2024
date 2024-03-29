#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // priority_queue<int> pq;
        ll max_elem = *max_element(nums.begin(), nums.end());
        ll j = 0;
        ll cnt = 0;
        ll ans = 0;
        ll n = nums.size();
        for(ll i=0;i<n;i++){
            if(nums[i] == max_elem) cnt++;
            while(cnt == k){
                ans += n-i;
                if(nums[j] == max_elem){
                    cnt--;
                } 
                j++;
            }
        }
        return ans;
    }
};