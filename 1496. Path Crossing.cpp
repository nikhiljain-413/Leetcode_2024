class Solution {
public:
    unordered_map<char, pair<int,int>> mp;
    set<pair<int,int>> st;
    bool isPathCrossing(string path) {
        mp['E'] = {1,0};
        mp['W'] = {-1,0};
        mp['N'] = {0,1};
        mp['S'] = {0,-1};
        st.insert({0,0});
        int x = 0,y=0;
        for(char ch: path){
            x += mp[ch].first;
            y += mp[ch].second;
            if(st.count({x, y})){
                return true;
            }
            st.insert({x, y});
        }
        return false;
    }
};