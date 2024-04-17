class Solution {
public:
    void kmp(string &aa, vector<int> &dp){
        int n = aa.size();
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int lastIndx = dp[i-1];
            while(lastIndx>0 && (aa[i] != aa[lastIndx])){
                lastIndx = dp[lastIndx - 1];
            }
            dp[i] = lastIndx + ((aa[i] == aa[lastIndx])?1:0);
        }
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        string a_s = a+"#"+s;
        string b_s = b+"#"+s;
        // cout<<a_s<<" "<<b_s<<endl;
        int sz_a = a_s.size();
        int sz_b = b_s.size();
        vector<int> dp_a_s(sz_a, 0);
        vector<int> dp_b_s(sz_b, 0);
        kmp(a_s, dp_a_s);
        kmp(b_s, dp_b_s);
        // for(auto it: dp_a_s)cout<<it<<" ";
        // cout<<endl;
        // for(auto it: dp_b_s)cout<<it<<" ";
        // cout<<endl;
        vector<int> matching_a_index;
        vector<int> matching_b_index;

        for(int i=0;i<sz_a;i++){
            if(dp_a_s[i]==a.size()){
                matching_a_index.push_back(i-2*a.size());
            }
        }
        for(int i=0;i<sz_b;i++){
            if(dp_b_s[i]==b.size()){
                matching_b_index.push_back(i-2*b.size());
            }
        }
        // for(auto it: matching_a_index)cout<<it<<" ";
        // cout<<endl;
        // for(auto it: matching_b_index)cout<<it<<" ";
        // cout<<endl;
        vector<int> ans;
        for(auto indx : matching_a_index){
            int low = indx-k;
            int high = indx+k;
            auto it = lower_bound(matching_b_index.begin(), matching_b_index.end(),low);
            if(it!=matching_b_index.end() && abs(*it - indx)<=k) {
                ans.push_back(indx);
                continue;
            }
            it = upper_bound(matching_b_index.begin(), matching_b_index.end(),low);
            if(it==matching_b_index.begin()) continue;
            --it;
            if(abs(*it - indx)<=k) ans.push_back(indx);
        }
        return ans;
    }
};