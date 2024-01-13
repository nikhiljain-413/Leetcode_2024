class Solution {
public:
    bool isvovel(char ch){
        return ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || 
               ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int half = n/2;
        int vovel=0;
        int con = 0;
        for(int i=0;i<half;i++){
            if(isvovel(s[i])) vovel++;
            con++;
        }
        for(int i=half;i<n;i++){
            if(isvovel(s[i])) vovel--;
            con--;
        }
        if(vovel==0 && con==0) return true;
        return false;
    }
};