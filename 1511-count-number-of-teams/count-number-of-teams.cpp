class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int i=1;i<n-1;i++){
            int small_left = 0;
            int small_right = 0;
            int large_left = 0;
            int large_right = 0;
            for(int j = i-1;j>=0;j--){
                if(rating[j]>rating[i]) large_left++;
                else small_left++;
            }
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i]) large_right++;
                else small_right++;
            }
            ans += (small_left * large_right);
            ans += (large_left * small_right);

        }
        
        return ans;
    }
};

