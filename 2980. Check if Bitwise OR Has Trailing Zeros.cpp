class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(auto num: nums){
            if((num & 1)==0) cnt++;
            if(cnt>=2) return true;
        }
        return false;
    }
};