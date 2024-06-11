class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        int n = arr2.size();
        for(int i=0;i<n;i++){
            mp[arr2[i]] = i;
        }
        int cnt = 0;
        n = arr1.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int val1 = mp.find(arr1[i])==mp.end()?1001:mp[arr1[i]];
                int val2 = mp.find(arr1[j])==mp.end()?1001:mp[arr1[j]];
                if(val1>val2) swap(arr1[i], arr1[j]);
            }
            if(mp.find(arr1[i])!=mp.end()) cnt++;
        }
        sort(arr1.begin()+cnt, arr1.end());
        return arr1;
    }
};