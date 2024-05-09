#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<ll> pq;
        for(auto h: happiness){
            pq.push(h);
        }
        ll i=0;
        ll ans = 0;
        while(pq.size() && k){
            if(pq.top() - i>=0){
                ans +=pq.top() - i;
                i++;k--;
            }
            else break;
            pq.pop();
        }
        return ans;
    }
};