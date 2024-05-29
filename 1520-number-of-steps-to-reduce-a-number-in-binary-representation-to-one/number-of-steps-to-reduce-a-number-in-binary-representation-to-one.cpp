class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(), s.end());
        while(s.back()=='0') s.pop_back();
        reverse(s.begin(), s.end());
        vector<int> zeros;
        int cnt = 0;
        while(s.back()=='0') s.pop_back(),cnt++;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0') zeros.push_back(i);
        }
        return zeros.size() + cnt + (s.size()>1?s.size()+1:0);

    }
};
