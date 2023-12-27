class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans = "";
        int dep = num;
        num = abs(num);
        int rem;
        while(num){
            rem = num%7;
            ans.push_back('0'+rem);
            num /= 7;
        }
        if(dep<0){
            ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};