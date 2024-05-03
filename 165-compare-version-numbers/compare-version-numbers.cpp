
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        int j=0;
        int i = 0;
        int ans1= 0;
        int ans2 = 0;
        for(;i<n;i++){
            if(version1[i]=='.'){
                ans2 = 0;
                for(;j<m;j++){
                    if(version2[j]=='.'){
                        if(ans1>ans2) return 1;
                        else if(ans1<ans2) return -1;
                        ans2 = 0;
                        j++;
                        break;
                    }
                    ans2 = ans2*10 + (version2[j]-'0');
                }
                if(j==m){
                    cout<<i<<" "<<j<<" "<<ans1<<" "<<ans2<<endl;
                    if(ans1>ans2) return 1;
                    else if(ans1<ans2) return -1;
                    ans2 = 0;
                }
                ans1 = 0;
                continue;
            }
            ans1 = ans1*10 + (version1[i]-'0');
        }
        
        for(;j<m;j++){
            if(version2[j]=='.'){
                if(ans1>ans2) return 1;
                else if(ans1<ans2) return -1;
                ans2 = 0;
                ans1 = 0;
                continue;
            }
            ans2 = ans2*10 + (version2[j]-'0');
        }
        if(i==n && j==m){
            cout<<i<<" "<<j<<" "<<ans1<<" "<<ans2<<endl;
            if(ans1>ans2) return 1;
            else if(ans1<ans2) return -1;
        }
        return 0;
    }
};