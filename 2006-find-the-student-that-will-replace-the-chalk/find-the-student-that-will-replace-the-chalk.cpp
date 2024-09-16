#define ll long long
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum = accumulate(chalk.begin(), chalk.end(),0LL);
        ll rem = k%sum;
        if(rem==0) return 0;
        ll n = chalk.size();
        for(ll i=0;i<n;i++){
            if(rem<chalk[i]){
                return i;
            }else{
                rem -= chalk[i];
            }
        }
        return 0;
    }
};