class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int pep = trust.size();
        if(n==1 && pep==0) return 1;
        map<int, set<int>> mp;
        set<int> present;
        for(int i=1;i<=n;i++){
            present.insert(i);
        }
        for(auto t: trust){
            mp[t[1]].insert(t[0]);
            if(present.find(t[0])!=present.end()){
                present.erase(t[0]);
            }
        }
        for(auto pr: mp){
            if(pr.second.size()==n-1 && present.find(pr.first)!=present.end()){
                return pr.first;
            }
        }
        return -1;
    }
};