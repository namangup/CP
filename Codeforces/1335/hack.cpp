#include<bits/stdc++.h>
#include<algorithm>
#define ll long long int
using namespace std;
 
const auto start_time = std::chrono::high_resolution_clock::now();
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;cin>>t;
    while(t--){
        ll n;
        int count=0;
        cin>>n;
        for(ll i=(n-1);i>(n/2);i--){
            count++;
        }
        cout<<count<<"\n";
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    #ifndef ONLINE_JUDGE
    cerr << "Time Taken : " << diff.count() << "s\n";
    #endif
}