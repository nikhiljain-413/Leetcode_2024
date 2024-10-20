class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            map<char,int> mp;
            int mx = 0;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                mx = max(mx, mp[s[j]]);
                if(mx>=k) cnt++;
            }
        }
        
        return cnt;
    }
};