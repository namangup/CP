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
#define vin(a,n) rep(i,n){int x;cin>>x;a.pb(x);}
#define arrin(arr,n) rep(i,n){cin>>arr[i];}
#define vp(a) rep(i,a.size()){cout<<a[i]<<" ";}
#define fbo find_by_order
#define ook order_of_key
/*
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vi a;
    vin(a,n);
    vector<ii> p,t;
    int x=-1,y=-1,r=-1,s=-1;
    rep(i,n)
    {
        if(i==0 && a[1]>a[0])
        {
            x=0;
        }
        if(i!=0 &&i!=(n-1)&& x==-1 && a[i-1]>a[i] && a[i+1]>a[i])
        {
            x=i-1;
        }
        if(x!=-1 &&i!=(n-1) && a[i+1]<a[i])
        {
            y=i+1;
            p.pb(mp(x,y));
            x=-1;
            y=-1;
            continue;
        }
        if(x!=-1 && i==(n-1))
        {
            y=n-1;
            p.pb(mp(x,y));
            x=-1;
            y=-1;
        }
    }
    rep(i,n)
    {
        if(i==0 && a[1]<a[0])
        {
            x=0;
        }
        if(i!=0 &&i!=(n-1)&& x==-1 && a[i-1]<a[i] && a[i+1]<a[i])
        {
            x=i-1;
        }
        if(x!=-1 &&i!=(n-1) && a[i+1]>a[i])
        {
            y=i+1;
            t.pb(mp(x,y));
            x=-1;
            y=-1;
            continue;
        }
        if(x!=-1 && i==(n-1))
        {
            y=n-1;
            t.pb(mp(x,y));
            x=-1;
            y=-1;
        }
    }
    for(auto i:p)
    {
        cout<<i.fi<<" "<<i.se;
        cout<<endl;
    }
    for(auto i:t)
    {
        cout<<i.fi<<" "<<i.se;
        cout<<endl;
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
    }
}