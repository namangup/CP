/******Author : c0d3rpr0********/
#include <bits/stdc++.h>
using namespace std;

const auto start_time = std::chrono::high_resolution_clock::now();

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<long long> vll;
typedef vector<char> vc;
typedef long double ld;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;
typedef vector<ll>::iterator vit;

const ll INF = 1LL<<18;
const ll MOD = 1e9 + 7;
const ll EPS = 1e-6;

#define      each(it,s)        for(vit it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<ll>())
#define      fill(a)           memset(a, 0, sizeof (a))
#define      rep(i, n)         for(ll i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(ll i = a; i < (n); ++i)
#define      repD(i, a, n)     for(ll i = a; i >= (n); --i)
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>
#define 	 rpq(x)			   priority_queue<x,std::vector<x>,compare>
#define      F                 first
#define      S                 second
#define      mp                make_pair
#define      pb                push_back
#define      vin(a,n)          vll a;rep(i,n){ll in;cin>>in;a.pb(in);}
#define      arrin(arr,n)      rep(i,n){cin>>arr[i];}
#define      fastio            ios_base::sync_with_stdio(false);cin.tie(NULL);
#define      ignore            cin.ignore(256,'\n');

ll gcd(ll x,ll y)              {if(x==0) return y;return gcd(y%x,x);}
ll powM(ll x,ll y,ll m)        {ll ans=1,r=1;x%=m;while(r>0&&r<=y){if(r&y){ans*=x;ans%=m;}r<<=1;x*=x;x%=m;}return ans;}
ll modI(ll a, ll m)            {ll m0=m,y=0,x=1;if(m==1) return 0;while(a>1){ll q=a/m;ll t=m;m=a%m;a=t;t=y;y=x-q*y;x=t;}if(x<0) x+=m0;return x;}
ll max(ll a,ll b,ll c)         {return max(max(a,b),c);}
ll power(ll x,ll y)            {ll z=1;while(y>0){if(y%2)z=(z*x);x =(x*x) ;y/=2;}return z;}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve()
{
    int n;
    cin>>n;
    short arr[n];
    rep(i,n)
    cin>>arr[i];
    int pre[n]={0};
    pre[0]=arr[0];
    unordered_set<int> s;
    repA(i,1,n)
    {
        pre[i]=arr[i]+pre[i-1];
        s.insert(pre[i]);
        rep(j,i-1)
        s.insert(pre[i]-pre[j]);
    }
    int ans=0;
    rep(i,n)
    {
        if(s.find(arr[i])!=s.end())
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("/home/naman/Desktop/CP/input.txt","r",stdin);
    freopen("/home/naman/Desktop/CP/output.txt","w",stdout);
    #endif
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    #ifndef ONLINE_JUDGE
    cerr << "Time Taken : " << diff.count() << "s\n";
    #endif
}