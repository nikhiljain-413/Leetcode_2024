#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    vector<int> v = {1,2,3};
    cout<<accumulate(v.begin(), v.end(),0);
}