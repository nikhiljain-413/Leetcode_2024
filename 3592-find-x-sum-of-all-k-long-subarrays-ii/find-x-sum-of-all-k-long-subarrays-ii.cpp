#define ll long long
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        map<ll,ll> mp;
        set<pair<ll,ll>> large, small;
        ll n = nums.size();
        vector<long long> ans;
        for(ll i=0;i<k;i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            small.insert({it.second, it.first});
        }
        ll large_sum = 0;
        while(large.size()<x && small.size()){
            auto small_last = *small.rbegin();
            small.erase(small_last);
            large.insert(small_last);
            large_sum += small_last.first * small_last.second;
        }
        ans.push_back(large_sum);
        for(ll i=k;i<n;i++){
            pair<ll,ll> inc = {mp[nums[i]], nums[i]};
            if(large.count(inc)){
                large.erase(inc);
                large_sum-=mp[nums[i]]* nums[i];
            }else {
                small.erase(inc);
            }
            mp[nums[i]]++;
            inc = {mp[nums[i]], nums[i]};
            small.insert(inc);

            pair<ll,ll> dec = {mp[nums[i-k]], nums[i-k]};
            if(large.count(dec)){
                large.erase(dec);
                large_sum -= mp[nums[i-k]]* nums[i-k];
            }else{
                small.erase(dec);
            }
            mp[nums[i-k]]--;
            dec = {mp[nums[i-k]], nums[i-k]};
            small.insert(dec);

            
            while(large.size()<x && small.size()){
                auto small_last = *small.rbegin();
                small.erase(small_last);
                large.insert(small_last);
                large_sum += small_last.first * small_last.second;
            }
            while(large.size() && small.size() && 
            (large.begin()->first<small.rbegin()->first || ((large.begin()->first==small.rbegin()->first) &&large.begin()->first*large.begin()->second<small.rbegin()->first*small.rbegin()->second))){
                auto large_first = *large.begin();
                auto small_last = *small.rbegin();
                large.erase(large_first);
                large_sum -= large_first.first*large_first.second;
                small.erase(small_last);
                large.insert(small_last);
                large_sum+=small_last.first*small_last.second;
                small.insert(large_first);
            }
            ans.push_back(large_sum);
        }




        return ans;
    }
};