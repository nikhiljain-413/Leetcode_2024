#define pii pair<int,int>
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        //wage quality
        vector<pii> v;
        int n = quality.size();
        for(int i=0;i<n;i++){
            v.push_back({wage[i], quality[i]});
        }
        sort(v.begin(), v.end(),[](pii &a, pii &b){
            return a.first*b.second>b.first*a.second;
        });
        //wage
        // for(auto it:v)cout<<it.first<<" ";
        // cout<<endl;
        //quality
        // for(auto it:v)cout<<it.second<<" ";
        // cout<<endl;
        //wage/quality
        // for(auto it:v)cout<<it.first*1.0/it.second<<" ";
        // cout<<endl;
        vector<int> pref(n,0);
        int sum = 0;
        priority_queue<int> pq;
        // pq.push(pref[n-1]);
        for(int i=n-1;i>=0;i--){
            pref[i] = v[i].second + sum;
            pq.push(v[i].second);
            sum+=v[i].second;
            if(pq.size()==k){
                sum-=pq.top();
                pq.pop();
            } 
        }
        //quality pref
        // for(auto it: pref) cout<<it<<" ";
        // cout<<endl;

        double ans = INT_MAX;
        for(int i=k-1;i<n;i++){
            int left = i-k;
            int tot = pref[left+1];
            // if(left>=0) tot-=pref[left];
            double temp = v[left+1].first*1.0/v[left+1].second * tot;
            ans = min(ans, temp);
            // cout<<i<<" "<<tot<<" "<<v[left+1].first*1.0/v[left+1].second<<" "<<temp<<" "<<ans<<endl;
        }
        // cout<<endl;
        return ans;
    }
};
// 5 10 20
// 30 70 50
// 6 7 2.5
// 7 70 + 35 = 105 70/10*15
// 6 30 + 120 = 150
// 2.5
// 1 1 3 10 10 
// 8 7 4  2  2
// 8 7  1.3 0.2 0.2
// 8 8+ 8+ 24 = 40
// 7 7 + 21 + 70 = 98
// 1.3 4 + 4/3*10*2 = 30.66667
// 0.2
// 0.2

// 362 438 443 251 343 147 366 120 129 97 
// 40 52 57 35 51 25 83 35 62 68 
// 9.05 8.42308 7.77193 7.17143 6.72549 5.88 4.40964 3.42857 2.08065 1.42647 
// 40 92 149 184 235 260 343 378 440 508 
// 5 260 9.05 2353 2353           (40 + 25 + 35 + 35 + 51 + 52) = 238 = 2153.9
// 6 303 8.42308 2552.19 2353     (52 + 25 + 35 + 35 + 51 + 57) = 255 = 2147.8854
// 7 286 7.77193 2222.77 2222.77  (57 + 25 + 35 + 35 + 51 + 62) = 265 = 2059.56145
// 8 291 7.17143 2086.89 2086.89  (35 + 25 + 35 + 51 + 62 + 68) = 276 = 1979.31468
// 9 324 6.72549 2179.06 2086.89  (51 + 25 + 83 + 35 + 62 + 68) = 324 = 2179.05876

// 35 51 83 62 68 
