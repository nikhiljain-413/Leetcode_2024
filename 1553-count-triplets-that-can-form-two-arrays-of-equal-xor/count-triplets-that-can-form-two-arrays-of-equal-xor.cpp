class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        for(int i=1;i<n;i++){
            arr[i]^=arr[i-1];
        }
        // for(auto it: arr) cout<<it<<" ";
        // cout<<endl;
        int cnt = 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                for(int k=0;k<j;k++){
                    int tot = arr[i];
                    if(k>0) tot^=arr[k-1];
                    int right = arr[i]^arr[j-1];
                    int left = tot^right;
                    if(left == right){
                        // cout<<k<<" "<<j<<" "<<i<<endl;
                        cnt++;
                    } 
                }
            }
        }
        return cnt;
    }
};