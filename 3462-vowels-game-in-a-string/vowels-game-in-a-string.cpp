class Solution {
public:
    bool doesAliceWin(string s) {
        set<char> st = {'a','e','i','o','u'};
        int cnt = 0;
        for(auto ch: s){
            if(st.find(ch)!=st.end()) cnt++;
        }
        if(cnt==0) return false;
        return true;
    }
};