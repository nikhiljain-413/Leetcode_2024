struct Node{
    public:
    Node* arr[26];
    bool flag = false;
    void add(char ch, Node* node){
        arr[ch-'a'] = node;
    }
    bool is_present(char ch){
        // cout<<ch<<" ";
        return arr[ch-'a']!=NULL;
    }
    Node* next(char ch){
        return arr[ch-'a'];
    }
    bool get_flag(){
        return flag;
    }
    void set_flag(){
        flag = true;
    }
};
class Solution {
public:
    vector<string> get_words(string sentence){
        vector<string> words;
        int i= 0;
        int n = sentence.size();
        for(int j=0;j<n;j++){
            if(sentence[j]==' '){
                string ss = sentence.substr(i,j-i);
                if(ss.size()) words.push_back(ss);
                i = j+1;
            }
        }
        string ss = sentence.substr(i,n-i);
        if(ss.size()) words.push_back(ss);
        return words;
    }
    string form(vector<string> words){
        string ans = "";
        for(auto word: words ){
            ans.append(word);
            ans.push_back(' ');
        }
        while(ans.back()==' ') ans.pop_back();
        return ans;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Node* start = new Node();
        for(auto word: dictionary){
            Node* traverse = start;
            for(auto ch: word){
                // cout<<ch<<" ";
                if(!traverse->is_present(ch)){
                    traverse->add(ch, new Node());
                }
                traverse = traverse->next(ch);
            }
            // cout<<endl;
            traverse->set_flag();
        }
        vector<string> words = get_words(sentence);
        // for(auto word: words) cout<<word<<"|";
        // cout<<endl;
        int nn = words.size();
        Node* traverse = start;
        // string a
        // for(auto ch: "cat"){
        //     if(traverse->is_present(ch))
        //     traverse = traverse->next(ch);
        //     else return "nahi bana";
        // }
        // return "";
        for(int i= 0;i<nn;i++){
            string word = words[i];
            // cout<<word<<endl;
            Node* traverse = start;
            int count = 0;
            bool flag = false;
            for(auto ch: word){
                // cout<<ch<<" ";
                count++;
                if(traverse->get_flag()){
                    flag = true;
                    break;
                }
                if(!traverse->is_present(ch)){
                    break;
                }
                traverse = traverse->next(ch);
            }
            // cout<<endl;
            if(flag) words[i] = words[i].substr(0, count-1);
        }

        return form(words);
    }
};