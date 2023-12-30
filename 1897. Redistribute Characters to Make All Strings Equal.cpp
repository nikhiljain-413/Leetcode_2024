class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> v(26,0);
        for(auto word: words){
            for(auto ch: word){
                v[ch-'a']++;
            }
        }
        int n = words.size();
        for(int i=0;i<26;i++){
            if(v[i]%n!=0){
                return false;
            }
        }
        return true;
    }
};