class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for(auto ch: s){
            int con = ch-'a'+1;
            int sum = (con/10) + (con%10);
            // cout<<sum<<" ";
            num += sum;
        }
        k--;
        while(k--){
            int new_num = 0;
            while(num){
                new_num += num%10;
                num/=10;
            }
            num = new_num;
        }
        return num;
    }
};