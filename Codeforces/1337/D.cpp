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
ll min(ll a,ll b,ll c){
	return min(min(a,b),c);
}
ll power(ll x,ll y){ll z=1;while(y>0){if(y%2)z=(z*x);x =(x*x) ;y/=2;}return z;}
ll eval(ll x,ll y,ll z)
{
    return (x-y)*(x-y)+(z-y)*(z-y)+(x-z)*(x-z);
}
void solve()
{
    ll nr,ng,nb;
    cin>>nr>>ng>>nb;
    //cout<<eval(1LL,1LL,1000000000LL)<<" ";
    set<ll> r,g,b;
    rep(i,nr)
    {
        ll x;
        cin>>x;
        r.insert(x);
    }rep(i,ng)
    {
        ll x;
        cin>>x;
        g.insert(x);
    }rep(i,nb)
    {
        ll x;
        cin>>x;
        b.insert(x);
    }
    sit i;
    ll m=INF*INF*2;
    for(i=r.begin();i!=r.end();i++)
    {
        sit j1,j2,k1,k2;
        j1=g.lower_bound(*i);
        k1=b.lower_bound(*i);
        j2=g.upper_bound(*i);
        k2=b.upper_bound(*i);
        ll k=min(eval(*i,*j1,*k1),eval(*i,*j1,*k2),eval(*i,*j2,*k1));
        m=min(m,k,eval(*i,*j2,*k2));
    }
    for(i=g.begin();i!=g.end();i++)
    {
        sit j1,j2,k1,k2;
        j1=r.lower_bound(*i);
        k1=b.lower_bound(*i);
        j2=r.upper_bound(*i);
        k2=b.upper_bound(*i);
        ll k=min(eval(*i,*j1,*k1),eval(*i,*j1,*k2),eval(*i,*j2,*k1));
        m=min(m,k,eval(*i,*j2,*k2));
    }
    for(i=b.begin();i!=b.end();i++)
    {
        sit j1,j2,k1,k2;
        j1=g.lower_bound(*i);
        k1=r.lower_bound(*i);
        j2=g.upper_bound(*i);
        k2=r.upper_bound(*i);
        ll k=min(eval(*i,*j1,*k1),eval(*i,*j1,*k2),eval(*i,*j2,*k1));
        m=min(m,k,eval(*i,*j2,*k2));
    }
    cout<<m<<"\n";

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