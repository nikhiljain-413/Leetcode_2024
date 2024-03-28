class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        int ret = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[j]]--;
                j++;
            }
            ret = max(ret, i-j+1);
        }
        return ret;
    }
};