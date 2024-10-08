class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int unbalance = 0;
        for(auto ch: s){
            if(ch == '[') st.push('[');
            if(ch ==']'){
                if( st.size() && st.top()=='[')
                st.pop();
                else unbalance++;
            }
        }
        return (unbalance+1)/2;
    }
};
