class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int prev = -1;
                bool flag = true;
                for(int k=0;k<i;k++){
                    if(nums[k]<=prev){
                        flag = false;
                        break;
                    }else{
                        prev = nums[k];
                    }
                }
                for(int k=j+1;k<n;k++){
                    if(nums[k]<=prev){
                        flag = false;
                        break;
                    }else{
                        prev = nums[k];
                    }
                }
                if(flag) cnt++;
            }
        }
        return cnt;
    }
};