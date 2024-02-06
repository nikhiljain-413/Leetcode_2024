class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string,int>> v;
        for(int i=0;i<n;i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            v.push_back({s,i});
        }
        sort(v.begin(), v.end());
        int j=0;
        vector<vector<string>> ans;
        vector<string> temp;
        temp.push_back(strs[v[0].second]);
        for(int i=1;i<n;i++){
            string s = v[i].first;
            int indx = v[i].second;
            if(s == v[j].first){
                temp.push_back(strs[indx]);
            }else{
                j = i;
                ans.push_back(temp);
                temp.clear();
                temp.push_back(strs[indx]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};