class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mp1,mp2;
        for(auto ch: s){
            mp1[ch]++;
        }
        for(auto ch: t){
            mp2[ch]++;
            if(mp2[ch]> mp1[ch]) return false;
        }
        for(auto pr: mp1){
            if(mp2[pr.first]!= pr.second){
                return false;
            }
        }
        return true;
    }
};