class Solution {
public:
    int numberOfMatches(int n) {
        int sum = 0;
        while(n){
            sum+=n/2;
            n =(n+1)/2;
            if(n==1) break;
        }
        return sum;
    }
};