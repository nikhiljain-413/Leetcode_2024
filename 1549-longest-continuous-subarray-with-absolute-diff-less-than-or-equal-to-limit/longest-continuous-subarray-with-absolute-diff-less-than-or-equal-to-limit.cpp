class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int n = nums.size();
        int ans=INT_MIN,j=0;
        for(int i=0;i<n;i++){
            ms.insert(nums[i]);

            if(*(ms.rbegin())-*(ms.begin())<=limit) ans=max(ans, i-j+1);
            else{
                while(*(ms.rbegin())-*(ms.begin())>limit){
                    auto it = ms.find(nums[j]);
                    ms.erase(it);j++;
                }

                ans=max(ans, i-j+1);
            }
        }

        return ans;
    }
};