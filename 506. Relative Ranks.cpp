class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // int first=INT_MIN,second=INT_MIN,third=INT_MIN;
        int n = score.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({score[i], i});
        }
        sort(temp.begin(), temp.end(), [](pair<int,int> &a, pair<int,int> &b){return a.first> b.first;});
        vector<string> ans(n);

        for(int i=0;i<n;i++){
            if(i==0){
                ans[temp[i].second] = "Gold Medal";
            }
            else if(i==1){
                ans[temp[i].second] = "Silver Medal";
            }
            else if(i==2){
                ans[temp[i].second] = "Bronze Medal";
            }else
                ans[temp[i].second] = to_string(i+1);
        }
        return ans;
    }
};