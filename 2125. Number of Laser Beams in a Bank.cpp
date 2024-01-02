class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // vector<int> v;
        int last = 0;
        int ans = 0;
        for(auto str: bank){
            int cnt = 0;
            for(auto ch: str){
                if(ch == '1') cnt++;
            }
            ans += last*cnt;
            if(cnt){
                last = cnt;
            } 
        }
        return ans;
    }
};