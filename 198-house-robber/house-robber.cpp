class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        if(n>1) ans = max(ans, nums[1]);
        for(int i=2;i<n;i++){
            int mx = nums[i-2];
            if(i-3>=0) mx = max(mx, nums[i-3]);
            nums[i]+=mx;
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
// 1 2 3 1
// 1 2 4 3