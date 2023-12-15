class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        for(auto path: paths){
            string u = path[0];
            string v = path[1];
            mp[u] = v;
        }
        string beg = paths[0][1];
        while(mp.find(beg)!=mp.end()){
            beg = mp[beg];
        }
        return beg;
    }
};