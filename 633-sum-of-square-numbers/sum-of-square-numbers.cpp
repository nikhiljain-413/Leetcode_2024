class Solution {
public:
    bool judgeSquareSum(int c) {
        int low = 0;
        int high = sqrt(c);
        for(int i=0;i<=high;i++){
            int no = c - i*i;
            int sqrt_no = sqrt(no);
            if(sqrt_no * sqrt_no == no) return true;
        }
        return false;
    }
};