class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> zeros(n,0);
        vector<int> ones(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zeros[i]++;
            }
            else
                ones[i]++;
            
        }
        for(int i=1;i<n;i++){
            zeros[i] += zeros[i-1];
            ones[i] += ones[i-1];
        }
        int mx = 0;
        for(int i=0;i<n-1;i++){
            mx = max(mx, zeros[i]+ones[n-1]-ones[i]);
        }
        return mx;
    }
};