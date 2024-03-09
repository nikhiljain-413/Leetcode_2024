class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto num: arr){
            mp[num]++;
        }
        vector<int> v;
        for(auto pr: mp){
            v.push_back(pr.second);
        }
        sort(v.begin(),v.end());
        int n = v.size();
        for(int i=1;i<v.size();i++){
            v[i]+=v[i-1];
        }
        int indx = upper_bound(v.begin(), v.end(),k)-v.begin();
        // cout<<indx<<endl;
        return n-indx;
    }
};