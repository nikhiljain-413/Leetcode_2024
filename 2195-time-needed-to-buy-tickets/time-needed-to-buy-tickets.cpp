class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = 0;
        int req = tickets[k];
        for(int i=0;i<n;i++){
            if(i<=k){
                ans += min(tickets[i], req);
            }else{
                ans += min(tickets[i], req-1);
            }
        }
        return ans;
    }
};
