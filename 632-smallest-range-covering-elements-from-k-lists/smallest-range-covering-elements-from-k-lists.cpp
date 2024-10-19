class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> range = {-1000000, 1000000};
        vector<int> vec(n, 0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int minEl = INT_MAX;
        int maxEl = INT_MIN;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        while(true){
            auto top = pq.top();
            pq.pop();
            int elem = top[0];
            int lstIndx = top[1];
            int elemIndx = top[2];
            minEl = elem;
            
            if(maxEl - minEl<range[1]-range[0]){
                range[0] = minEl;
                range[1] = maxEl;
            }
            if(elemIndx+1>=nums[lstIndx].size()) break;
            elemIndx++;
            pq.push({nums[lstIndx][elemIndx], lstIndx, elemIndx});
            maxEl = max(maxEl, nums[lstIndx][elemIndx]);

        }
        return range;
    }
};