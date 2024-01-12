class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int> mp1,mp2;
        for(auto ch: s){
            mp1[ch]++;
        }
        int common=0;
        for(auto ch: t){
            mp2[ch]++;
            if(mp2[ch]<=mp1[ch]) common++;
        }
        return t.size()-common;
    }
};