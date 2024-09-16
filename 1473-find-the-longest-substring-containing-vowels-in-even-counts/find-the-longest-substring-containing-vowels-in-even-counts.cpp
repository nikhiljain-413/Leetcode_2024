class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> v(26, 0);
        v['a'-'a'] = 1;
        v['e'-'a'] = 2;
        v['i'-'a'] = 4;
        v['o'-'a'] = 8;
        v['u'-'a'] = 16;
        map<int, int> mp;
        int pref = 0;
        mp[0] = -1;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            pref = pref ^ v[s[i]-'a'];
            if(mp.find(pref)==mp.end()){
                mp[pref] = i;
            }else{
                ans = max(ans, i-mp[pref]);
            }
        }
        return ans;
    }
};