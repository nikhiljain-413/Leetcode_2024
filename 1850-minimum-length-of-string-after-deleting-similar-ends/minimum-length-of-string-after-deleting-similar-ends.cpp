class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            char ch = s[l];
            if(s[l]==s[r]){
                while(s[l]==ch){
                    l++;
                }
                while(l<r && s[r]==ch){
                    r--;
                }
            }else{
                break;
            }
        }
        return max(0, r-l+1);
    }
};