class Solution {
public:

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int> diff;
        int n = heights.size();
        int ans = 0;
        multiset<int> mx;
        int brick_used = 0;
        bool flag = true;
        for(int i=1;i<n;i++){
            if(heights[i]-heights[i-1]<=0){
                continue;
            }
            int diff = heights[i]-heights[i-1];
            if(mx.size()<ladders){
                mx.insert(diff);
            }
            else {
                mx.insert(diff);
                brick_used += *mx.begin();
                mx.erase(mx.begin());
                if(brick_used>bricks){
                    flag = false;
                    ans = i-1;
                    break;
                }
            }
            
        }
        if(flag) return n-1;
        return ans;
    }
};