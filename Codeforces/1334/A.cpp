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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ignore cin.ignore(256,'\n');
/*
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */
void solve()
{
    int n;
    cin>>n;
    vi p,c;
    rep(i,n)
    {
        int x,y;
        cin>>x>>y;
        p.pb(x);
        c.pb(y);
    }
    if(p[0]<c[0])
    {
        cout<<"NO"<<endl;
        return ;
    }
    int f=1;
    repA(i,1,n-1)
    {
        if(p[i]<p[i-1]||c[i]<c[i-1])
        {
            f=0;
            break;
        }
        if((p[i]-p[i-1])<(c[i]-c[i-1]))
        {
            f=0;
            break;
        }
    }
    string ans=f?"YES":"NO";
    cout<<ans<<endl;
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}