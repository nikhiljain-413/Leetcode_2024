class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> trails;
        for(int i=0;i<n;i++){
            auto it = lower_bound(trails.begin(), trails.end(), nums[i]);
            if(it == trails.end()) trails.push_back(nums[i]);
            else *it = nums[i];
        }
        return trails.size();
    }
};