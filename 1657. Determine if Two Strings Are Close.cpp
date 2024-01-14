class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1 == word2) return true;
        if(word1.size()!=word2.size()) return false;
        map<char, int> mp1, mp2, mp;
        int n = word1.size();

        for(int i=0;i<n;i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
            mp[word1[i]]++;
            mp[word2[i]]--;
            if(mp[word1[i]]==0) mp.erase(word1[i]);
            if(mp[word2[i]]==0) mp.erase(word2[i]);
        }
        if(mp.size()==0) return true;
        if(mp1.size()!=mp2.size()) return false;
        multiset<int> s1,s2;
        auto it1 = mp1.begin();
        auto it2 = mp2.begin();
        for(;it1!=mp1.end(),it2!=mp2.end();it1++,it2++){
            if(it1->first!=it2->first) return false;
            s1.insert(it1->second);
            s2.insert(it2->second);
        }
        auto t1 = s1.begin();
        auto t2 = s2.begin();
        for(;t1!=s1.end(),t2!=s2.end();t1++,t2++){
            if(*t1!=*t2) return false;
        }
        return true;
    }
};