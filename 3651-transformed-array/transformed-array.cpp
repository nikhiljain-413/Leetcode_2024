class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i] = nums[(i+nums[i]+100*n)%n];
        }
        return ans;
    }
};