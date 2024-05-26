#define ll long long
class Solution {
public:
    long long numberOfPairs(vector<int>& num1, vector<int>& num2, int k) {
        ll ans = 0;
        map<ll,ll> mp1, mp2;
        vector<ll> nums1;
        
        for(auto num: num1){
            if(num%k==0) mp1[num]++;
        }
        for(auto num: num2){
            mp2[num]++;
        }
        for(auto pr: mp1){
            nums1.push_back(pr.first);
        }
        // for(auto pr: mp2){
        //     nums2.push_back(pr.first);
        // }
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        // ll n = nums1.size();
        // ll m = nums2.size();
        for(auto it: nums1) cout<<it<<" ";
        cout<<endl;
        // for(auto it: nums2) cout<<it<<" ";
        // cout<<endl;
        // for(auto pr: mp2){
        //     ll i = lower_bound(nums1.begin(), nums1.end(), pr.first) - nums1.begin();
        //     ll temp = 0;
        //     for(;i<n;i++){
        //         // cout<<i<<" "<<n<<endl;
        //         if((nums1[i] % (pr.first*k))==0) temp+=mp1[nums1[i]];
        //     }
        //     ans += pr.second*temp;
        // }
        for(auto num: nums1){
            num = num/k;
            ll temp = 0;
            for(int i=1;i*i<=num;i++){
                if(num%i==0 && mp2.find(i)!=mp2.end()){
                    temp+=mp2[i];
                }
                if(num%i==0 && i!=num/i && mp2.find(num/i)!=mp2.end()){
                    temp += mp2[num/i];
                }
            }
            ans += mp1[num*k]*temp;

        }
        return ans;
    }
};
