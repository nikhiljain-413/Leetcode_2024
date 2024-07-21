#define ll long long
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        ll ver = 0;
        ll hor = 0;
        priority_queue<pair<ll,ll>> pq;
        for(auto it: horizontalCut){
            pq.push({it,0});
        }
        for(auto it: verticalCut){
            pq.push({it,1});
        }
        ll ans = 0;
        while(pq.size()){
            ll cost = pq.top().first;
            ll dir = pq.top().second;
            cout<<cost<<" "<<dir<<endl;
            if(dir == 0){
                ans += (ver+1)*cost;
                hor++;
            }
            else {
                ans += (hor+1)*cost;
                ver++;
            }
            pq.pop();
        }
        return ans;
    }
};