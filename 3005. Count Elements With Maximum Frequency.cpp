class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int mx = 0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            mx = max(mx, mp[nums[i]]);
        }
        int ans = 0;
        for(auto it: mp){
            if(it.second==mx){
                ans+=mx;
            }
        }
        return ans;
    }
};