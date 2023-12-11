class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int cnt = n/4;
        int i = 0;
        int j = 1;
        int temp = 1;
        // if(arr[0] == arr[1]) temp = 1;
        while(j<n){
            while(j<n && arr[j-1]==arr[j]){
                j++;
                temp++;
            }
            if(temp>cnt) return arr[i];
            temp = 1;
            i = j;
            j++;
        }
        return arr[0];
    }
};