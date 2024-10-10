class Solution {
public:

    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.size()==0) st.push(i);
            else{
                if(nums[i]<nums[st.top()]){
                    st.push(i);
                }
            }
        }
        // while(st.size()){
        //     cout<<st.top()<<" ";
        //     st.pop();
        // } 
        // cout<<endl;
        int ans = 0;
        int j = n-1; 
        while(j>=0){
            while(st.size() && nums[j]>=nums[st.top()]){
                ans = max(ans, j-st.top());
                st.pop();
            }  
            j--;
        }
        return ans;
    }
};