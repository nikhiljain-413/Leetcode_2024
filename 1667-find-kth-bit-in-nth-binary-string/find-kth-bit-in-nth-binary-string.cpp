class Solution {
public:
    string inverse(string s){
        string form = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            form.push_back('0' + 1-(s[i]-'0'));
        }
        return form;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=1;i<n;i++){
            string new_s = s;
            new_s.push_back('1');
            reverse(s.begin(), s.end());
            new_s.append(inverse(s));
            s = new_s;
            // cout<<s<<" ";
        }
        // cout<<endl;
        // cout<<s<<" ";
        return s[k-1];
    }
};
