class Solution {
public:
    int solve(int num, int next){
        int i = min((int)sqrt(num), next);
        for(;i>1;i--){
            if(num%i==0){
                // cout<<num<<" ";
                return i;
            } 
        }
        return -1;
    }
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        // cout<<nums.back()<<" ";
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]) continue;
            else{
                nums[i] = solve(nums[i], nums[i+1]);
                // cout<<nums[i]<<" ";
                if(nums[i]==-1) return -1;
                cnt+=1;
            }
        }
        return cnt;
    }
};