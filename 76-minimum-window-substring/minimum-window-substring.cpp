class Solution {
public:
    string solve(string &s, string &t, int len){
        map<char,int> mp;
        for(auto it: t) mp[it]++;
        // int l =0,r=0;
        int n = s.size();
        int cnt = t.size();
        int i=0;
        // for(;i<len;i++){
        //     if(mp[s[i]] > 0) cnt--;
        //     mp[s[i]]--;
        // }
        // if(cnt==0) return s.substr(0,len);
        for(;i<n;i++){
            // int temp = i-len;
            if(i>=len){
                mp[s[i-len]]++;
                if(mp[s[i-len]] > 0) cnt++;
            }
            if(mp[s[i]] > 0) cnt--;
            mp[s[i]]--;
            if(i>=len-1 && cnt==0) return s.substr(i-len+1,len);
        }
        return  "";
    }
    // bool ispossible(string &s, string &t, int len){
    //     map<char,int> mp;
    //     for(auto it: t) mp[it]++;
    //     int l =0,r=0;
    //     int n = s.size();
    //     int i=0;
    //     int cnt = t.size();
    //     for(;i<len;i++){
    //         if(mp[s[i]] > 0) cnt--;
    //         mp[s[i]]--;
    //     }
    //     if(cnt==0) return true;
    //     for(;i<n;i++){
    //         mp[s[i-len]]++;
    //         if(mp[s[i-len]] > 0) cnt++;
    //         if(mp[s[i]] > 0) cnt--;
    //         mp[s[i]]--;
    //         if(cnt==0) return true;
    //     }
    //     return  false;
    // }
    string minWindow(string s, string t) {
        int low = t.size();
        int high = s.size();
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(solve(s,t,mid)!=""){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(ans == -1) return "";
        return solve(s,t, ans);
    }
};