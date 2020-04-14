#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<long long int> vll;
typedef vector<char> vc;
typedef long double ld;

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;
typedef string::iterator strit;
typedef vector<long long int>::iterator vllit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
const int EPS = 1e-6;
const auto start_time = std::chrono::high_resolution_clock::now();

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(vit it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(int i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(int i = a; i >= (n); --i)
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>
#define 	 rpq(x)			   priority_queue<x,std::vector<x>,compare>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define vin(a,n) vi a;rep(i,n){int in;cin>>in;a.pb(in);}
#define arrin(arr,n) rep(i,n){cin>>arr[i];}
#define vp(a) rep(i,a.size()){cout<<a[i]<<" ";}
#define fbo find_by_order
#define ook order_of_key
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ignore cin.ignore(256,'\n');

void solve()
{
    int n;
    cin>>n;
    vi a,b;
    rep(i,n)
    {
        int x;
        cin>>x;
        a.pb(x);
        if(x%4!=0 && x%2==0)
        b.pb(-1);
        else if(x%4==0)
        b.pb(0);
        else
        {
            b.pb(1);
        }
        cout<<b[i]<<" ";
    }
    cout<<"\n";
    int dp[n]={0};
    ll pos=1,neg=0,tot=(ll)n*(n+1)/2;
    ll r=0;
    repA(i,0,n-1)
    {
        if(b[i]==0)
        {
            r+=pos*neg;
            cout<<i<<" "<<pos<<" "<<neg<<" "<<r<<"\n";
            pos=1;
            neg=0;
            continue;
        }
        else if((i>0&&b[i-1]==0&&b[i]!=0)||(i==0&&b[i]!=0))
        {
            dp[i]=b[i];
            dp[i]==1?pos++:neg++;
            continue;
        }
        dp[i]=b[i]*dp[i-1];
        dp[i]==1?pos++:neg++;
    }
    r+=pos*neg;
    cout<<n<<" "<<pos<<" "<<neg<<" "<<r<<"\n";
    rep(i,n)
    cout<<dp[i]<<" ";
    cout<<"\n";
    ll ans=tot-r;
    //cout<<"\n"<<pos<<" "<<neg<<"\n";
    cout<<ans<<"\n";
}
int main()
{
    fastio;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    cerr << "Time Taken : " << diff.count() << "s\n";
}