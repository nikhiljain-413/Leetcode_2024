class Solution {
public:
    vector<vector<string>> all_vector;
    vector<string> temp, ans;
    set<string> dict;
    bool ispossible(string s){
        return dict.find(s)!=dict.end();
    }
    void solve(int i, string &s){
        if(i==s.size()){
            all_vector.push_back(temp);
            return;
        }
        for(int k=i;k<s.size();k++){
            string str = s.substr(i, k-i+1);
            if(ispossible(str)){
                temp.push_back(str);
                solve(k+1, s);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string &s, vector<string>& wordDict) {
        for(auto word: wordDict){
            dict.insert(word);
        }
        solve(0, s);
        for(auto t: all_vector){
            string tt = "";
            for(auto strr: t){
                tt.insert(tt.end(), strr.begin(), strr.end());
                tt.push_back(' ');
            }
            tt.pop_back();
            ans.push_back(tt);
        }
        return ans;
    }
};