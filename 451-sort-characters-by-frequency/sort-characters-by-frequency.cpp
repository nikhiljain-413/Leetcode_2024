class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        vector<pair<int,char>> v;
        for(auto ch: s){
            mp[ch]++;
        }
        for(auto pr: mp){
            v.push_back({pr.second, pr.first});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        string ans = "";
        for(auto pr: v){
            char ch = pr.second;
            int freq = pr.first;
            for(int j=0;j<freq;j++){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};