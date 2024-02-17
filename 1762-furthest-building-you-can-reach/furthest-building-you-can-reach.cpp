class Solution {
public:

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int> diff;
        vector<int> indx;
        int n = heights.size();
        for(int i=1;i<n;i++){
            if(heights[i]-heights[i-1]>0){
                diff.push_back(heights[i]-heights[i-1]);
                indx.push_back(i);
            }
        }
        int ans = 0;
        multiset<int> mx;
        int brick_used = 0;
        bool flag = true;
        for(int i=0;i<diff.size();i++){
            if(mx.size()<ladders){
                mx.insert(diff[i]);
            }
            else {
                mx.insert(diff[i]);
                brick_used += *mx.begin();
                mx.erase(mx.begin());
                if(brick_used>bricks){
                    flag = false;
                    ans = indx[i]-1;
                    break;
                }
            }
        }
        if(flag) return n-1;
        return ans;
    }
};