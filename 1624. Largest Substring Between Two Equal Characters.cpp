class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(int i=0;i<n;i++){
            mp[s[i]] = i;
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            if(mp[s[i]]!=i){
                ans = max(ans, mp[s[i]]-i-1);
            }
        }
        return ans;
    }
};