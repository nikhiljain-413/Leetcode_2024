class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string s;
        stringstream ss(sentence);
        vector<string> words;
        while(getline(ss, s ,' ')){
            words.push_back(s);
        }
        int i = 1;
        for(auto word: words){
            if(word.size()>=searchWord.size() && word.substr(0,searchWord.size()) == searchWord) return i;
            i++;
        }
        return -1;
    }
};
