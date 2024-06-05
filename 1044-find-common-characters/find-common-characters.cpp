class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<int,int> mp, mp1;
        int i = 0;
        for(auto w: words){
            mp1.clear();
            if(i==0){
                for(auto ch: w){
                    mp[ch]++;
                }
                i = 1;
                continue;
            }
            for(auto ch: w){
                mp1[ch]++;
            }
            for(auto it: mp){
                mp[it.first] = min(mp1[it.first], it.second);
            }
        }
        vector<string> ans;
        for(auto it: mp){
            for(int i=0;i<it.second;i++){
                string temp = "";
                temp.push_back(it.first);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};