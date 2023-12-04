class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        for(int i=n-3;i>=0;i--){
            if(num[i] == num [i+1] && num[i+1] == num[i+2]){
                string temp = num.substr(i,3);
                if(temp>ans) ans = temp;
            }
        }
        return ans;
    }
};