struct Node{
    Node* arr[26];
    int flag = -1;
    void setFlag(int indx){
        flag = flag==-1?indx:flag;
    }
    int getFlag(){
        return flag;
    }
    bool hasNext(char ch){
        return arr[ch-'a']!=NULL;
    }
    Node* next(char ch){
        return arr[ch-'a'];
    }
    void put(char ch){
        arr[ch-'a'] = new Node();
    }
};
class Solution {
public:
    Node* start = new Node();
    int isPrefixOfWord(string sentence, string searchWord) {
        string s;
        stringstream ss(sentence);
        vector<string> words;
        while(getline(ss, s ,' ')){
            words.push_back(s);
        }
        int indx = 1;
        Node* trav;
        for(auto word: words){
            trav = start;
            cout<<indx<<" "<<word<<endl;
            for(auto ch: word){
                cout<<ch<<endl;
                if(!trav->hasNext(ch)){
                    trav->put(ch);
                }
                trav = trav->next(ch);
                trav->setFlag(indx);
            }
            // if(trav->getFlag()==-1) trav->setFlag(indx);
            indx++;
        }
        trav = start;
        for(auto ch: searchWord){
            if(trav->hasNext(ch)){
                trav = trav->next(ch);
            }else{
                return -1;
            }
        }
        return trav->getFlag();
    }
};
