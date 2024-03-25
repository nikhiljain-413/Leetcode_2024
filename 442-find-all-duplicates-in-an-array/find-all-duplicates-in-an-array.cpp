class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int indx = abs(nums[i]);
            if(nums[indx-1]<0){
                ans.push_back(indx);
                continue;
            } 
            nums[indx-1] = -1*nums[indx-1]; 
        }
        return ans;
    }
};