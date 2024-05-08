class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> v;
        int n = score.size();
        for(int i=0;i<n;i++){
            v.push_back({-score[i],i});
        }
        sort(v.begin(), v.end());
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            int indx = v[i].second;
            string str = "";
            if(i==0){
                str = "Gold Medal";
            }else if(i==1){
                str = "Silver Medal";
            }else if(i==2){
                str = "Bronze Medal";
            }else{
                str = to_string(i+1);
            }
            ans[indx] = str;
        }
        return ans;
    }
};