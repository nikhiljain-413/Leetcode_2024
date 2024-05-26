class Solution {
public:
    // int vv[22];

    bool rec(string s,int i, vector<string>& d,vector<string> v,set<vector<string>> &all_s){
        int n = s.size();
        if(i==n){
            all_s.insert(v);
            return true;
        } 
        // if(find(d.begin(),d.end(),s.substr(i,n-i)) != d.end()) return true;
        // if(vv[i]!=-1) return vv[i];
        bool ans = false;
        for(int k = i;k<n;k++){
            string str = s.substr(i,k-i+1);
            if(find(d.begin(),d.end(),str) != d.end()){
                v.push_back(str);
                rec(s,k+1,d,v,all_s);
                v.pop_back();
            }
        }
        // return vv[i] = ans;
        return ans;
    }
    string con(vector<string> v){
        string ret = "";
        for(auto s:v){
            ret.append(s);
            ret.push_back(' ');
        }
        ret.pop_back();
        return ret;
    }
    vector<string> wordBreak(string s, vector<string>& d) {
        // memset(vv,-1,sizeof(vv));
        set<vector<string>> all_s;
        // if(find(d.begin(),d.end(),s) != d.end()) return true;
        vector<string> v;
        rec(s,0,d,v,all_s);
        vector<string> ret;
        for(auto vv: all_s){
            ret.push_back(con(vv));
        }
        return ret;
    }
};