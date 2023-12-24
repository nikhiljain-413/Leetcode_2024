class Solution {
public:
    int minOperations(string s) {
        int bit = 0;
        int ans1 = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'+bit){
                ans1++;
            }
            bit = 1-bit;
        }
        int ans2 = 0;
        bit = 1;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'+bit){
                ans2++;
            }
            bit = 1-bit;
        }
        return min(ans1, ans2);
    }
};