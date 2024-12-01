class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(auto it: arr) mp[it]++;
        for(auto it: arr){
            if(it==2*it && mp[it]>1) return true;
            if(it!=2*it && mp[2*it]) return true;
        }
        return false;
    }
};