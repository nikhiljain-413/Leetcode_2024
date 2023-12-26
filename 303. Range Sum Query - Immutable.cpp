class NumArray {
public:
    vector<int> pref;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        pref = nums;
        for(int i=1;i<n;i++){
            pref[i] += pref[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return pref[right] - pref[left] + nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */