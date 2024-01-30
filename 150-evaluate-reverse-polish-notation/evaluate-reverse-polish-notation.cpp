class Solution {
public:
    bool isoperator(string str){
        return (str=="+")||(str=="-")||(str=="*")||(str=="/");
    }
    int convert(string str){
        int n = str.size();
        int ans = 0;
        bool neg = false;
        int i = 0;
        if(str[0]=='-'){
            neg = true;
            i++;
        }
        for(;i<n;i++){
            ans = ans*10 + (str[i]-'0');
        }
        if(neg) ans = -1*ans;
        return ans;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto tok: tokens){
            if(isoperator(tok)){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int c;
                if(tok=="+") c = a+b;
                else if(tok=="-") c=a-b;
                else if(tok=="*") c=a*b;
                else if(tok=="/") c=a/b;
                st.push(c);
            }else{
                st.push(convert(tok));
            }
        }
    return st.top();
    }
};