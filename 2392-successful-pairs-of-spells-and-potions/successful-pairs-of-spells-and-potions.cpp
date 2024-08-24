
#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        ll n = potions.size();
        for(auto spell: spells){
            ll mn = (success+spell-1)/spell;
            ll indx = lower_bound(potions.begin(), potions.end(), mn) - potions.begin();
            ans.push_back(n-indx);
        }
        return ans;
    }
};