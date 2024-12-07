class Solution {
public:
    bool is_possible(int mid, vector<int>& nums, int maxOperations){
        int cnt = 0;
        for(auto it: nums){
            cnt += (it-1)/mid;
        }
        return cnt<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(is_possible(mid, nums, maxOperations)){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};

