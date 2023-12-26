class Solution {
public:
    bool isPerfectSquare(int num) {
        int a = sqrt(num);
        return a*a == num;
    }
};