class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1 == s2) return 0;
        int n = s1.size();
        int X=0;
        int Y=0;
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;
            if(s1[i]=='x') X++;
            else Y++;
        }
        if((X+Y)%2!=0) return -1;
        return X/2 + Y/2 + ((X%2)?2:0);
    }
};