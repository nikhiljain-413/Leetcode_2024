class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        for(auto ch: chars){
            mp[ch]++;
        }
        int sum = 0;
        for(auto word: words){
            unordered_map<char,int> temp;
            bool count = 1;
            for(auto ch: word){
                temp[ch]++;
                if(temp[ch]>mp[ch]){
                    count=0;
                    break;
                }
            }
            // for(auto pr: temp){
            //     if(mp[pr.first]<pr.second){
            //         count=0;
            //         break;
            //     }
            // }
            if(count)
            sum+=word.size();
        }
        return sum;
    }
};