class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<pair<int,int>, pair<int,char>>>v;
        int n = positions.size();
        for(int i=0;i<n;i++){
            v.push_back({{positions[i],i},{healths[i],directions[i]}});
        }
        sort(v.begin(), v.end());
        stack<pair<pair<int,int>, pair<int,char>>> st;
        for(auto pr: v){
            int pos = pr.first.first;
            // cout<<pos<<" ";
            int indx = pr.first.second;
            int health = pr.second.first;
            int dir = pr.second.second;
            int flag = true;
            while(dir=='L' && st.size() && st.top().second.second=='R'){
                if(health == st.top().second.first){
                    st.pop();
                    flag = false;
                    break;
                }
                else if(health > st.top().second.first){
                    st.pop();
                    health -= 1;
                }else{
                    st.top().second.first -= 1;
                    flag = false;
                    break;
                }
            }
            if(flag)
                st.push({{pos,indx},{health,dir}});
                // st.push(pr);
        }
        // cout<<endl;
        vector<pair<int, int>> ans;
        while(st.size()){

            // cout<<st.top().second.first<<" ";
            ans.push_back({st.top().first.second, st.top().second.first});
            st.pop();
        }
        sort(ans.begin(), ans.end());
        vector<int> ret;
        for(auto it: ans){
            ret.push_back(it.second);
        }
        // reverse(ans.begin(), ans.end());
        return ret;
    }
};
// 11 16 44
// 1 17 20
// r r l