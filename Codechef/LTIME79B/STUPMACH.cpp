#include <bits/stdc++.h>
using namespace std;


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
#define vin(a,n) rep(i,n){ll x;cin>>x;a.pb(x);}
#define arrin(arr,n) rep(i,n){cin>>arr[i];}
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
    int t;
    cin>>t;
    rep(i,t)
    {
        int n;
        cin>>n;
        vll s;
        vin(s,n);
        ll ans=n;
        ll mx=n;
        for(ll j=1;;j++)
        {
            ll x=0;
            auto min=min_element(s.begin(),s.begin()+mx);
            ans+=mx*(*min-j);
            j+=*min-j;
            x=min-s.begin();
            mx=x;
            ans+=mx;
            /*rep(k,mx)
            {
                if(s[k]==j)
                {
                    x=k;
                    mx=x;
                    break;
                }
                if(k==mx-1)
                x=mx;
            }*/
            //cout<<x<<endl;
            if(x==0)
            break;
        }
        cout<<ans<<endl;
    }
}