class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return 0;
        vector<int> pref(n);
        pref[0] = abs(t[0] - s[0]);
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + abs(t[i]-s[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int diff = pref[i];
            if(diff<=maxCost){
                ans = max(ans, i+1);
                continue;
            } 
            int to_find = diff - maxCost;
            int indx = lower_bound(pref.begin(), pref.end(), to_find) - pref.begin();
            ans = max(ans, i-indx);

        }
        return ans;
    }
};
// 2
// 1 1 1 2 1
// 1 2 3 5 6

