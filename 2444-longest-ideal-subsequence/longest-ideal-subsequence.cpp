class Solution {
public:
    int longestIdealString(string s, int k) {
        map<int, int> mp;
        int n = s.size();
        vector<int> ans(n,0);
        int mx = 1;
        for(int i=0;i<n;i++){
            int curr = s[i]-'a';
            int back = curr-k;
            int front = curr+k;
            int temp = 1;
            // if(i==3) cout<<curr<<" "<<back<<" "<<front<<endl;
            for(int i=curr; i>=max(0,back);i--){
                if(mp.find(i)!= mp.end()){
                    // if(i==3) cout<<mp[(i)]<<" "<<ans[mp[(i)]]<<endl;
                    temp = max(temp, 1+ans[mp[i]]);
                }
            }
            for(int i=curr; i<=min(26,front);i++){
                if(mp.find(i)!= mp.end()){
                    // if(i==3) cout<<mp[(i)]<<" "<<ans[mp[(i)]]<<endl;
                    temp = max(temp, 1+ans[mp[(i)]]);
                }
            }
            ans[i] = temp;
            mp[s[i]-'a'] = i;
            mx = max(mx, ans[i]);
        }

        return mx;
    }
};