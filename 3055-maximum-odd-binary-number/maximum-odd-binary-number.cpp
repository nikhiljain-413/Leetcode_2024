class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        while(left <= right){
            if(s[left]=='0' && s[right]=='1'){
                swap(s[left], s[right]);
                left++;
                right--;
                continue;
            }
            if(s[left]=='1') left++;
            if(s[right]=='0') right--;
        }
        swap(s[left-1], s[n-1]);
        return s;
    }
};