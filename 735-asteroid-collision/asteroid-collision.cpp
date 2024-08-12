class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> pq;
        for(auto ast: asteroids){
            if(pq.size() && pq.top()>0 && ast<0){
                    // cout<<( pq.top())<<" ";
                while(pq.size() && pq.top()>0 && abs(ast)>pq.top()){
                    pq.pop();
                }
                if(pq.size() && pq.top()>0 && abs(ast)==pq.top())  pq.pop();
                else if(pq.size() && pq.top()>0 && abs(ast)<pq.top()) continue;
                else{
                    pq.push(ast);
                }
            }else{
                pq.push(ast);
            }
        }
        vector<int> nums;
        while(pq.size()){
            nums.push_back(pq.top());
            pq.pop();
        } 
        reverse(nums.begin(), nums.end());
        return nums;
    }
};