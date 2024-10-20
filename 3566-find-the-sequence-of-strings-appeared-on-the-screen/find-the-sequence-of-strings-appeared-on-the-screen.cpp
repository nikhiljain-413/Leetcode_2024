class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string temp = "";
        int n = target.size();
        for(int i=0;i<n;i++){
            temp.push_back('a');
            ans.push_back(temp);
            int diff = target[i]-'a';
            for(int i=1;i<=diff;i++){
                temp.pop_back();
                temp.push_back('a'+i);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};