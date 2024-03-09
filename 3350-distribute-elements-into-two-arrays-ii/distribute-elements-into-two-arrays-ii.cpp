#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
pair<int,int>, 
null_type, 
less<pair<int,int>>, 
rb_tree_tag, 
tree_order_statistics_node_update> 
ordered_set;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1,v2;
        ordered_set s1,s2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        s1.insert({nums[0], 0});
        s2.insert({nums[1], 1});
        for(int i=2;i<n;i++){
            int num = nums[i];
            int indx1 = s1.order_of_key({num+1, 0});
            int indx2 = s2.order_of_key({num+1, 0});
            int cnt1 = v1.size() - indx1;
            int cnt2 = v2.size() - indx2;
            // cout<<cnt1<<" "<<cnt2<<endl;
            if(cnt1>cnt2){
                v1.push_back(num);
                s1.insert({num, i});
            }
            else if(cnt1<cnt2){
                v2.push_back(num);
                s2.insert({num, i});
            }
            else{
                if(v1.size()<v2.size()){
                    v1.push_back(num);
                    s1.insert({num, i});
                }
                else if(v1.size()>v2.size()){
                    v2.push_back(num);
                    s2.insert({num, i});
                }
                else{
                    v1.push_back(num);
                    s1.insert({num, i});
                }
            }

        }
        // cout<<v1.size();
        for(auto num: v2){
            v1.push_back(num);
        }
        return v1;
    }
};