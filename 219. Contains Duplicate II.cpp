class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<min(n,k);i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                return true;
            }
        }
        for(int i=k;i<n;i++){
            mp[nums[i]]++;
            if( mp[nums[i]]>1){
                return true;
            }
            mp[nums[i-k]]--;
        }
        return false;
    }
};