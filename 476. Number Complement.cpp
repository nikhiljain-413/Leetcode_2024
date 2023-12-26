class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int last = 0;
        for(int i=0;i<31;i++){
            if(num & 1<<i){
                last = i;
            }
        }
        for(int i=0;i<=last;i++){
            if(num & 1<<i){
                continue;
            }
            else{
                ans |= (1<<i);
            }
        }
        return ans;
    }
};