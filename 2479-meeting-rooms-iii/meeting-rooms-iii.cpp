#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        cout<<meetings.size()<<endl;
        set<ll> vacant;
        vector<ll> used(n,0);
        map<ll, vector<ll>> free;
        
        for(ll i=0;i<n;i++){
            vacant.insert(i);
        }
        ll start=0;
        ll end;
        for(auto met : meetings){
            start = max(start, met[0]*1ll);
            ll time = met[1]-met[0];
            // while(free.size() && free.begin()->first<=start){
            //     for(auto f: free.begin()->second){
            //         vacant.insert(f);
            //     }
            //     free.erase(free.begin());
            // }
            for(auto itt= free.begin();itt!=free.end();){
                if(itt->first<=start){
                    for(auto f: itt->second){
                        vacant.insert(f);
                    }
                    auto temp = itt;
                    itt++;
                    free.erase(temp);
                }else{
                    break;
                }
            }
            if(vacant.size()>0){
            }else{
                auto it = free.begin();
                start = max(start, it->first);
                cout<<start<<" ";
                for(auto f: it->second){
                    vacant.insert(f);
                }
                free.erase(it);
            }
            auto it = vacant.begin();
            ll room = *it;
            vacant.erase(it);
            free[start+time].push_back(room);
            cout<<room<<" "<<start<<" "<<start+time<<endl;
            used[room]++;
        }
        ll mx = 0;
        ll room_no = 0;
        for(ll i=0;i<n;i++){
            if(used[i]>mx){
                mx = max(mx, used[i]);
                room_no = i;
            }
        }
        return room_no;
    }
};