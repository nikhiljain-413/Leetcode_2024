class Solution {
public:
    string losingPlayer(int x, int y) {
        int mn = min(x, y/4);
        if(mn%2) return "Alice";
        return "Bob";
    }
};