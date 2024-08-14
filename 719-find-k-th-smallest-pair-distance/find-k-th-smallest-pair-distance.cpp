class Solution {
public:
    bool solve(vector<int>& nums, int mid, int k){
        int cnt = 0;
        int j = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            // cout<<nums[i]-nums[j]<<" "<<k<<endl;
            if(nums[i]-nums[j]>mid){
                // cout<<"gaya"<<" ";
                while(j<=i && nums[i]-nums[j]>mid){
                    j++;
                }
            }
            cnt += (i-j);
        }
        // cout<<mid<<" "<<cnt<<endl;
        return cnt>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = 1e6;
        int ans;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(solve(nums, mid, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};