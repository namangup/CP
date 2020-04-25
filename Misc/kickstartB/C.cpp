/******Author : c0d3rpr0********/
#include <bits/stdc++.h>
using namespace std;

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
typedef string::iterator strit;
typedef vector<long long>::iterator vllit;

const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 3;
const ll EPS = 1e-6;
const auto start_time = std::chrono::high_resolution_clock::now();

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(vit it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<ll>())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      rep(i, n)         for(ll i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(ll i = a; i < (n); ++i)
#define      repD(i, a, n)     for(ll i = a; i >= (n); --i)
#define 	 pq(x)			   priority_queue<x,std::vector<x>,compare>
#define 	 rpq(x)			   priority_queue<x,std::vector<x>,compare>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define vin(a,n) vll a;rep(i,n){ll in;cin>>in;a.pb(in);}
#define arrin(arr,n) rep(i,n){cin>>arr[i];}
#define vp(a) rep(i,a.size()){cout<<a[i]<<" ";}
#define fbo find_by_order
#define ook order_of_key
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ignore cin.ignore(256,'\n');
ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
ll powM(ll x,ll y,ll m)
{
    ll ans=1,r=1;
    x%=m;
    while(r>0&&r<=y)
    {
        if(r&y)
        {
            ans*=x;
            ans%=m;
        }
        r<<=1;
        x*=x;
        x%=m;
    }
    return ans;
}
ll modI(ll a, ll m)
{
    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}
ll max(ll a,ll b,ll c){
	return max(max(a,b),c);
}
ll power(ll x,ll y){ll z=1;while(y>0){if(y%2)z=(z*x);x =(x*x) ;y/=2;}return z;}
#define F 1000000000LL
ll solve()
{
    string s;
    cin>>s;
    ll a[4]={0};
    ll b[4]={0};
    ll x=0;
    rep(i,s.length())
    {
        char c=s[i];
        if((c-48)>=2 && (c-48)<=9)
        {
            x=c-48;
            i+=2;
            while(s[i]!=')')
            {
                char ch=s[i];
                if(ch=='N') b[0]++;
                else if(ch=='E') b[1]++;
                else if(ch=='S') b[2]++;
                else b[3]++;
                i++;
            }
            rep(j,4) a[j]+=x*b[j];
            rep(j,4) b[j]=0;
        }
        else
        {
            if(c=='N') a[0]++;
            else if(c=='E') a[1]++;
            else if(c=='S') a[2]++;
            else a[3]++;
        }
    }
    rep(i,4) cout<<a[i]<<" ";
    ll ay=(-a[0]+a[2])%F;
    ll ax=(-a[4]+a[1])%F;
    ax+=1;
    ay+=1;
    if(ax<=0)
    ax+=F;
    if(ay<=0)
    ay+=F;
    cout<<ax<<" "<<ay<<"\n";
    return 0;
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
    ignore;
    rep(i,t)
    {
        cout<<"Case #"<<i+1<<": ";
        solve();
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    #ifndef ONLINE_JUDGE
    cerr << "Time Taken : " << diff.count() << "s\n";
    #endif
}