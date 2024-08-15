class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt_5 = 0;
        int cnt_10 = 0;
        // int cnt_20 = 0;
        for(auto bill: bills){
            if(bill==5){
                cnt_5++;
                continue;
            }else if(bill==10){
                if(cnt_5){
                    cnt_5--;
                    cnt_10++;
                }else{
                    return false;
                }
            }else{
                if(cnt_10 && cnt_5){
                    cnt_10--;
                    cnt_5--;
                }else if(cnt_5>=3){
                    cnt_5-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};