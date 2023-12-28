int dp[101][27][101][101];
class Solution {
public:
    string s;
    unordered_set<int> st = {1,9,99};
    int solve(int indx, char prev_char, int cnt, int k){
        if(k<0) return INT_MAX/4;
        if(indx==s.size()) return 0;
        if(dp[indx][prev_char-'a'][cnt][k]!=-1){
            return dp[indx][prev_char-'a'][cnt][k];
        }
        int notremove;
        int remove = solve(indx+1,prev_char,cnt, k-1);
        if(s[indx]==prev_char){
            notremove = solve(indx+1,prev_char,cnt+1,k) +( (st.count(cnt))?1:0);
        }
        else{
            notremove = solve(indx+1,s[indx],1,k) + 1;
        }
        int ans = min(remove, notremove);
        return dp[indx][prev_char-'a'][cnt][k] = ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        this->s = s;
        memset(dp, -1, sizeof(dp));
        return solve(0,'z'+1,0,k);
    }
};