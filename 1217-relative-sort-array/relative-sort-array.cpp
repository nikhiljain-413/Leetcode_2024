class Solution {
public:
    map<int,int> mp;
    void merge(vector<int>& arr1, int low, int mid, int high){
        vector<int> temp(high - low+1);
        int i = low;
        int j = mid+1;
        int k = 0;
        while(i<=mid && j<=high){
            int val1 = mp.find(arr1[i])==mp.end()?1001:mp[arr1[i]];
            int val2 = mp.find(arr1[j])==mp.end()?1001:mp[arr1[j]];
            // if(arr1[i]<arr1[j]) temp[k++] = arr1[i++];
            // else temp[k++] = arr1[j++];

            if(val1<val2 || (val1 == val2 && val1==1001 && arr1[i]<arr1[j])) temp[k++] = arr1[i++];
            else temp[k++] = arr1[j++];
        }
        while(i<=mid){
            temp[k++] = arr1[i++];
        }
        while(j<=high){
            temp[k++] = arr1[j++];
        }
        for(int k = low;k<=high;k++){
            arr1[k] = temp[k-low];
        }
    }
    void merge_sort(vector<int>& arr1, int low, int high){
        if(low>=high) return;
        int mid = low + (high - low)/2;
        merge_sort(arr1, low, mid);
        merge_sort(arr1, mid+1, high);
        merge(arr1, low, mid, high);
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        int n = arr2.size();
        for(int i=0;i<n;i++){
            mp[arr2[i]] = i;
        }
        n = arr1.size();
        merge_sort(arr1, 0, n-1);
        // int cnt = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int val1 = mp.find(arr1[i])==mp.end()?1001:mp[arr1[i]];
        //         int val2 = mp.find(arr1[j])==mp.end()?1001:mp[arr1[j]];
        //         if(val1>val2) swap(arr1[i], arr1[j]);
        //     }
        //     if(mp.find(arr1[i])!=mp.end()) cnt++;
        // }
        // sort(arr1.begin()+cnt, arr1.end());
        return arr1;
    }
};