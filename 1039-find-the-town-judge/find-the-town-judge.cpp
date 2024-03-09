class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int pep = trust.size();
        if(n==1 && pep==0) return 1;
        map<int, set<int>> mp;
        vector<int> present(n+1,0);
        for(auto t: trust){
            mp[t[1]].insert(t[0]);
            present[t[0]] = 1;
        }
        for(auto pr: mp){
            if(pr.second.size()==n-1 && !present[pr.first]){
                return pr.first;
            }
        }
        return -1;
    }
};