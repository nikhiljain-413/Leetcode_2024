class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 0;
        int j = n-1;
        int cnt = 0;
        int ans = 0;
        while(i<=j){
            int temp = 0;
            while(i<=j && tokens[i]<=power){
                cnt++;
                ans = max(ans, cnt);
                power -= tokens[i];
                i++;
                temp++;
            }
            if(i<=j && cnt>0){
                cnt--;
                ans = max(ans, cnt);
                power += tokens[j];
                j--;
                temp++;
            }
            if(!temp) break;
        }
        return ans;
    }
};