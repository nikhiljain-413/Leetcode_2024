class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> winners,losers;
        for(auto match: matches){
            winners[match[0]]++;
            losers[match[1]]++;
        }
        vector<int> a,b;
        for(auto pr: losers){
            if(pr.second==1){
                b.push_back(pr.first);
            }
        }
        for(auto pr: winners){
            if(losers.find(pr.first)==losers.end()){
                a.push_back(pr.first);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return {a,b};

    }
};