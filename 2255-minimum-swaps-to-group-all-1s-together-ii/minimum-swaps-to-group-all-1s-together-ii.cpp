class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones_window = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int max_ones_in_window = 0;
        int ones_in_window = 0;
        int start = 0;
        for(int i=0;i<2*n;i++){
            if(nums[i%n]) ones_in_window++;
            if(i-start+1>ones_window){
                if(nums[start%n]) ones_in_window--;
                start++;
            }
            max_ones_in_window = max(max_ones_in_window, ones_in_window);
        }
        return ones_window - max_ones_in_window;
    }
};