#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ll tot = 0;
        ll n = nums.size();
        for(ll i=0;i<n;i++){
            tot+=nums[i];
        }
        sort(nums.begin(), nums.end());
        for(ll i=n-1;i>=0;i--){
            if(tot-nums[i]>nums[i]){
                break;
            }else{
                tot-=nums[i];
                nums.pop_back();
            }
        }
        if(nums.size()>2) return tot;
        return -1;
    }
};