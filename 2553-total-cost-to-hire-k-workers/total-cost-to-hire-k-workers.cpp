#define ll long long
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<ll, vector<ll>, greater<ll>> pq1,pq2;
        ll n = costs.size();
        ll i=0;
        for(;i<candidates;i++){
            cout<<costs[i]<<" ";
            pq1.push(costs[i]);
        }
        cout<<endl;
        ll j = n-1;
        for(;j>=i && candidates;j--,candidates--){
            cout<<costs[j]<<" ";
            pq2.push(costs[j]);
        }
        ll ans = 0;
        cout<<endl;
        while(k--){
            ll temp = INT_MAX;
            if(pq1.size()) temp = min(temp, pq1.top());
            if(pq2.size()) temp = min(temp, pq2.top());
            cout<<temp<<" ";
            ans += temp;
            if(pq1.size() && temp == pq1.top()){
                pq1.pop();
                if(i<=j)pq1.push(costs[i++]);
            }
            else if(pq2.size() && temp == pq2.top()){
                pq2.pop();
                if(i<=j)pq2.push(costs[j--]);
            }
        }
        return ans;
    }
};
// 0 1 2 3 4 5 6 7 