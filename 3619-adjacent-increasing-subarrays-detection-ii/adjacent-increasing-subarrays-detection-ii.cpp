class Solution {
public:
    bool ispossible(vector<int>& temp, int mid){
        int n = temp.size();
        for(int i=0;i<=n-2*mid;i++){
            if(temp[i]>=mid && temp[i+mid]>=mid) return true;
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n,1);
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                temp[i] = temp[i+1]+1;
            }
        }
        int low = 1;
        int high = n/2;
        int ans = 1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(ispossible(temp, mid)){
                low = mid+1;
                ans = mid;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};