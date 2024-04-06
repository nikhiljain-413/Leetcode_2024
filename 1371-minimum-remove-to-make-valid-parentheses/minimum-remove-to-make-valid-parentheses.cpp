class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        for(auto ch: s){
            if(ch == '(') st.push('(');
            if(ch == ')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(')');
            }
        }
        int rem1 = 0;
        int rem2 = 0;
        // )))(((
        while(!st.empty()){
            if(st.top()==')') rem1++;
            else rem2++;
            st.pop();
        }
        // reverse(to_remove.begin(), to_remove.end());
        int i = 0;
        string ss = "";
        for(auto ch: s){
            if((ch == ')') && rem1){
                rem1--;
                continue;
            }
            ss.push_back(ch);
        }
        s = "";
        for(int i=ss.size()-1;i>=0;i--){

            if((ss[i] == '(') && rem2){
                rem2--;
                continue;
            }
            s.push_back(ss[i]);
        }
        reverse(s.begin(), s.end());
        return s;
    }
};