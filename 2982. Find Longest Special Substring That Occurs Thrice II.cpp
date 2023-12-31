class Solution {
public:
    bool ispossible(string &s, int mid){
        int n = s.size();
        int prev = 'z'+1;
        vector<int> v(26,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]==prev){
                cnt++;
            }else{
                prev=s[i];
                cnt=1;
            }
            if(cnt>=mid){
                v[s[i]-'a']++;
                if(v[s[i]-'a']>=3){
                    return true;
                }
            }
        }
        return false;
    }
    int maximumLength(string &s) {
        int n = s.size();
        int low = 1;
        int high = n-2;
        int ans = -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(ispossible(s, mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};