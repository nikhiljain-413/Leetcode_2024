class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s = "";
        string s1 = "";
        int n = word1.size();
        int n1 = word2.size();
        for(auto word: word1){
            s.append(word);
        }
        for(auto word: word2){
            s1.append(word);
        }
        if(s==s1) return true;
        return false;
    }
};