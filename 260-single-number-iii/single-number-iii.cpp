#define ll long long
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ll orr_containing_both_element = 0;
        for(auto num: nums){
            orr_containing_both_element ^= num;
        }
        ll mask = orr_containing_both_element & -orr_containing_both_element;
        ll n = nums.size();
        ll orr_containing_first_element = 0;
        for(auto num: nums){
            if(num & mask){
                orr_containing_first_element ^=num;
            }
        }
        return{(int)orr_containing_first_element, (int)(orr_containing_both_element^orr_containing_first_element)};
    }
};