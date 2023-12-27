class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char prev = colors[0];
        int ans = 0;
        int i=0;
        int n = colors.size();
        while(i<n){
            char curr = colors[i];
            int temp=neededTime[i];
            int mx = neededTime[i];
            i++;
            while(i<n && colors[i]==curr){
                temp+=neededTime[i];
                mx = max(mx, neededTime[i]);
                i++;
            }
            ans+= temp-mx;
        }
        return ans;
    }
};