#define ll long long
class Solution {
public:
    int totalMoney(int n) {
        int week = n/7;
        int rem = n%7;
        return ((7*8)/2) * week + 7*week*(week-1)/2 + (rem*(rem+1)/2) + rem*week;
    }
};