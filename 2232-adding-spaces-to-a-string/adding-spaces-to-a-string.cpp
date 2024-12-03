class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ss = "";
        int n = s.size();
        int j = 0;
        for(int i=0;i<n;i++){
            if(j<spaces.size() && i==spaces[j]){
                ss.push_back(' ');
                j++;
            }
            ss.push_back(s[i]);
        }
        return ss;
    }
};