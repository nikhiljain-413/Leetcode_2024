class Solution {
public:
    bool isIncreasingSubarray(vector<int>& nums, int indx, int k){
        for(int i=indx;i<indx+k-1;i++){
            if(nums[i] >= nums[i+1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<=n-2*k;i++){
            if(isIncreasingSubarray(nums, i,k) && isIncreasingSubarray(nums,i+k,k)) return true;
        }
        return false;
    }
};