class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> temp(n,0);
        temp[n-1] = n-1;
        char max_el = s[n-1];
        int max_indx = n-1;
        for(int i=n-2;i>=0;i--){
            if(s[i]>max_el){
                max_el = s[i];
                max_indx = i;
            }
            temp[i] = max_indx;
        }
        for(int i=0;i<n;i++){
            if(i!=temp[i] && s[i]!=s[temp[i]]){
                swap(s[i], s[temp[i]]);
                break;
            }
        }
        return stoi(s);
    }
};