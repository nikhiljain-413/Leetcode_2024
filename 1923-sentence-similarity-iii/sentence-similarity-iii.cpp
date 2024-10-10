#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areSentencesSimilar(string str1, string str2) {
        istringstream iss(str1);
        vector<string> v1,v2;
        string word1, word2;
        while(getline(iss, word1, ' ')){
            v1.push_back(word1);
        }
        istringstream iss2(str2);
        while(getline(iss2, word2, ' ')){
            v2.push_back(word2);
        }
        while(v1.size() && v2.size() && v1.back() == v2.back()){
            v1.pop_back();
            v2.pop_back();
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        while(v1.size() && v2.size() && v1.back() == v2.back()){
            v1.pop_back();
            v2.pop_back();
        }
        if(v1.size()==0 || v2.size()==0) return true;
        return false;
    }
};