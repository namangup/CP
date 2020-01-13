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
    ll a[n];
    arrin(a,n);
    ll b[n];
    b[0]=0;
    //cout<<b[0]<<" ";
    for(int i=1;i<n-1;i++)
    {
        if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))
        b[i]=b[i-1]+1;
        else
        {
            b[i]=b[i-1];
        }
        //cout<<b[i]<<" ";
    }
    b[n-1]=b[n-2];
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        l--;
        r--;
        if((r-l)==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if((r-l)==2)
        {
            ll i=l+1;
            if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))
            cout<<"YES"<<endl;
            else
            {
                cout<<"NO"<<endl;
            }
            continue;
        }
        ll k=b[r-1]-b[l+1];
        if(b[l+1]!=b[l])
        {
            k++;
        }
        //cout<<k<<endl;
        if(k%2==1)
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
}
//01233