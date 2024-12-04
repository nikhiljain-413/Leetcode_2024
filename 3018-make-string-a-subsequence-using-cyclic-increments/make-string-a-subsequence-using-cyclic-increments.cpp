class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int j = 0;
        for(int i=0;i<n;i++){
            int indx1 = str1[i]-'a';
            int indx2 = str2[j]-'a';
            if(indx1==indx2 ||(indx1+1)%26==indx2%26 ){
                j++;
            }
            if(j==m) return true;
        }
        return false;
    }
};