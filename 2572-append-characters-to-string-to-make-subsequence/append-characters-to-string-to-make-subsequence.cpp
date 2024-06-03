class Solution {
public:
    int appendCharacters(string s, string t) {
        int j = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(j==t.size()) break;
            if(s[i]==t[j])j++;
        }
        return t.size()-j;
    }
};