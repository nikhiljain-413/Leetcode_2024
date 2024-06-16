class SegmentTree{
    vector<int> segTree;
    public:
    SegmentTree(int n){
        segTree.resize(4*n+1);
    }
    int combine(int a, int b){
        return a+b;
    }
    int isPeak(int indx, vector<int>& nums){
        int n = nums.size();
        return indx>0 && indx<(n-1) && nums[indx]>nums[indx-1] && nums[indx]>nums[indx+1];
    }
    void built(int node, int start, int end, vector<int>& nums){
        if(start == end){
            segTree[node] = isPeak(start, nums);
            return;
        }
        int mid = start + (end - start)/2;
        built(2*node+1, start, mid, nums);
        built(2*node+2, mid+1, end, nums);
        segTree[node] = combine(segTree[2*node+1] , segTree[2*node+2]);
    }
    void update(int node, int start, int end, int indx, vector<int>& nums){
        if(start == end){
            segTree[node] = isPeak(start, nums);
            return;
        }
        int mid = start + (end - start)/2;
        if(start<=indx && indx<=mid){
            update(2*node+1, start, mid, indx, nums);
        } 
        else{
            update(2*node+2, mid+1, end, indx, nums);
        } 
        segTree[node] = combine(segTree[2*node+1] , segTree[2*node+2]);
    }
    int query(int node, int start, int end, int left, int right){
        if(right<start || end<left){
            return 0;
        }
        if(left<=start && end<=right) return segTree[node];
        int mid = start + (end - start)/2;
        int p1 = query(2*node+1, start, mid, left, right);
        int p2 = query(2*node+2, mid+1, end, left, right);
        return p1+p2;
    }
};
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree st(n);
        st.built(0,0,n-1,nums);
        vector<int> ans;
        for(auto q: queries){
            if(q[0] == 1){
                int left = q[1];
                int right = q[2];
                if(right - left+1 < 3){
                    ans.push_back(0);
                    continue;
                }
                int temp = st.query(0,0,n-1,left+1,right-1);
                ans.push_back(temp);
            }else{
                int indx = q[1];
                int val = q[2];
                nums[indx] = val;
                for(int i=max(1,indx-1); i<=min(n-2, indx+1);i++){
                    st.update(0,0,n-1,i,nums);
                }
            }
        }
        return ans;
    }
};