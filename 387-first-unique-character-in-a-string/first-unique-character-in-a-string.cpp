class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(v[ch-'a']==0){
                v[ch-'a'] = i+1;
            }else{
                v[ch-'a'] = -1;
            }
        }
        for(auto it: v)cout<<it<<" ";
        cout<<endl;
        int ans = INT_MAX;
        for(int i=0;i<26;i++){
            if(v[i]>0){
                ans = min(ans, v[i]);
            }
        }
        return ans==INT_MAX?-1:ans-1;
    }
};