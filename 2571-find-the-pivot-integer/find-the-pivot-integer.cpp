class Solution {
public:
    int pivotInteger(int n) {
        int low = 1;
        int high = n;
        int ans = -1;
        int tot = n*(n+1)/2;
        cout<<tot<<endl;
        while(low<=high){
            int mid = low + (high-low)/2;
            int sum1 = mid * (mid+1)/2;
            int sum2 = tot - sum1 + mid;
            cout<<mid<<"-"<<sum1<<" "<<sum2<<endl;
            if(sum1 == sum2){
                return mid;
            }
            else if(sum1>sum2){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
};