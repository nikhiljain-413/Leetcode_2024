class Solution {
public:
    void kmp(string &aa, vector<int> &lps){
        int n = aa.size();
        lps[0]=0;
        for(int i=1;i<n;i++){
            int lastIndx = lps[i-1];
            while(lastIndx>0 && aa[lastIndx]!=aa[i]){
                lastIndx = lps[lastIndx-1];
            }
            lps[i] = lastIndx + ((aa[lastIndx]==aa[i])?1:0);
        } 
    }
    vector<int> beautifulIndices(string s, string a, string b, int kk) {
        string aa = a+"#"+s;
        string bb = b+"#"+s;
        int s1 = aa.size();
        int s2 = bb.size();
        vector<int> lps1(s1), lps2(s2);
        kmp(aa, lps1);
        kmp(bb, lps2);
        int a_sz = a.size();
        int b_sz = b.size();
        vector<int> v1,v2;
        for(int i=a_sz+1;i<s1;i++){
            if(lps1[i]==a_sz){
                v1.push_back(i-2*a_sz);
            }
        }
        for(int i=b_sz+1;i<s2;i++){
            if(lps2[i]==b_sz){
                v2.push_back(i-2*b_sz);
            }
        }
        for(auto it: v1) cout<<it<<" ";cout<<endl;
        for(auto it: v2) cout<<it<<" ";
        vector<int> ans;
        for(auto num: v1){
            int left = num-kk;
            int right = num+kk;
            auto it1 = lower_bound(v2.begin(), v2.end(),left);
            if(it1!=v2.end()){
                if(abs(*it1-num)<=kk){ ans.push_back(num);continue;}
            }
            // it1--;
            auto it2 = upper_bound(v2.begin(), v2.end(),right);
            if(it2==v2.begin()) continue;
            it2--;
            if(abs(*it2-num)<=kk){ ans.push_back(num);continue;}
        }
        return ans;
    }
};