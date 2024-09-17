class Solution {
public:
    
    void allWords(string s1, map<string, int> &mp){
        int i = 0;
        int j = 0;
        int n = s1.size();
        while(i<n){
            j= i;
            while(i<n && s1[i]!=' '){
                i++;
            }
            mp[s1.substr(j,i-j)]++;
            i++;
        }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp1, mp2;
        allWords(s1, mp1);
        allWords(s2, mp2);

        vector<string> ans;
        for(auto pr: mp1){
            if(pr.second==1 && mp2.find(pr.first)==mp2.end()){
                ans.push_back(pr.first);
            }
        }
        for(auto pr: mp2){
            if(pr.second==1 && mp1.find(pr.first)==mp1.end()){
                ans.push_back(pr.first);
            }
        }
        return ans;
    }
};