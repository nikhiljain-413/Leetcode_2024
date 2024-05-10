#define pii pair<int,int>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        k--;
        vector<pii> v;
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v.push_back({arr[i], arr[j]});
            }
        }
        sort(v.begin(), v.end(), [](const pii &a, const pii &b){
            return (a.first*b.second < b.first*a.second);
        });
        return {v[k].first, v[k].second};
    }
};