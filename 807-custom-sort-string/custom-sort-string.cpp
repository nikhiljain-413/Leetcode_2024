class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> v(26, 0);
        for(auto ch: s){
            v[ch-'a']++;
        }
        string ss = "";
        for(auto ch: order){
            int cnt = v[ch-'a'];
            for(int i=0;i<cnt;i++){
                ss.push_back(ch);
            }
            v[ch-'a'] = 0;
        }
        for(int i=0;i<26;i++){
            int cnt = v[i];
            for(int j=0;j<cnt;j++){
                ss.push_back(i+'a');
            }
            v[i] = 0;
        }
        return ss;
    }
};