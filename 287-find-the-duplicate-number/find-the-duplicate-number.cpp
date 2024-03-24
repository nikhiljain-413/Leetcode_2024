class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            int indx = abs(nums[i]);
            if(nums[indx]<0) return indx;
            nums[indx] = -1*nums[indx];
        }
        return 0;
    }
};

