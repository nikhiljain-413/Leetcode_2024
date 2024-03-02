class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                s[i]='0';
                cnt++;
            }
        }
        for(int i=0;i<cnt-1;i++){
            s[i] = '1';
        }
        if(cnt)
        s[n-1] = '1';
        return s;
    }
};