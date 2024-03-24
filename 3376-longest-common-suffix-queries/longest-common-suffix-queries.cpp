struct node{
    node* arr[26];
    int indx = INT_MAX;
    int sz = INT_MAX;
    void add(char ch, node* newNode){
        arr[ch-'a'] = newNode;
    }
    bool hasNext(char ch){
        return arr[ch-'a']!=NULL;
    }
    node* next(char ch){
        return arr[ch-'a'];
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        node* start = new node();
        int start_sz = INT_MAX;
        int start_indx;
        for(int j = 0;j<wc.size();j++){
            string s = wc[j];
            int n = wc[j].size();
            if(n<start_sz){
                start_sz = n;
                start_indx = j;
            }
            auto temp = start;
            for(int i=n-1;i>=0;i--){
                char ch = s[i];
                if(!temp->hasNext(ch)){
                    temp->add(ch, new node());
                }
                temp = temp->next(ch);
                if(temp->sz>n){
                    temp->sz = n;
                    temp->indx = j;
                }
            }
        }
        start->indx = start_indx;
        start->sz = start_sz;
        // start->update(start_indx, start_sz);
        vector<int> ans;
        for(int j = 0;j<wq.size();j++){
            auto temp = start;
            string s = wq[j];
            int n = wq[j].size();
            int temp_ans = start_indx;
            // int temp_ans = 0;
            for(int i=n-1;i>=0;i--){
                char ch = s[i];
                if(temp->hasNext(ch)){
                    temp = temp->next(ch);
                    temp_ans = temp->indx;
                    // temp_ans++;

                }else break;
            }
            ans.push_back(temp_ans);
        }
        for(auto it: ans) cout<<it<<" ";
        return ans;
    }
};