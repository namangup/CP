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

#define      rep(i, n)         for(ll i = 0; i < (n); ++i)
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
#define vp(a) rep(i,a.size()){cout<<a[i]<<" ";}
#define fbo find_by_order
#define ook order_of_key
/*
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */
ull power(ull x, ull y, ull p) 
{ 
    ull res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t;
    cin>>t;
    ull fac[100010];
    fac[0]=1;
    for(ll i=1;i<=100009;i++)
    {
        fac[i]=(fac[i-1]*i)%MOD;
    }
    while(t--)
    {
        ll n;
        cin>>n;
        vll a;
        ll s=0;
        rep(i,2*n)
        {
            ll x;
            cin>>x;
            a.pb(x);
            s+=a[i];
        }
        //cout<<s<<endl;
        if(s%(n+1)!=0)
        {
            cout<<0<<endl;
            continue;
        }
        ll k=s/(n+1);
        //cout<<k<<endl;
        vll skip;
        int flag=0,count=0;
        ll j=2*n;
        if(n<1000)
        { 
            rep(i,j)
            {
                if(count==2)
                {
                    flag=1;
                    break;
                }
                if(a[i]==k)
                {
                    skip.pb(i);
                    count++;
                }
            }
            //cout<<count<<endl;
            if(count==2)
            flag=1;
            if(!flag)
            {
                cout<<0<<endl;
                continue;
            }
        }
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        unordered_multiset<ll> q;
        int count3=0;
        vector<pair<ll,ll>> p;
        int count2=0;
        rep(i,j)
        {
            if(a[i]==k&&count<2)
            {
                count++;
                skip.pb(i);
            }
            if(skip.size()>0&&(i==skip[0]||i==skip[1]))
            continue;
            ll x=k-a[i];
            auto k=q.find(x);
            if(k!=q.end())
            {
                count3++;
                p.pb(mp(min(x,a[i]),max(x,a[i])));
                if(x==a[i])
                count2++;
                q.erase(k);
            }
            else
            {
                q.insert(a[i]);
            }  
        }
        //cout<<*q.begin()<<endl;
        if(q.size()!=0)
        {
            cout<<0<<endl;
            continue;
        }
        sort(p.begin(),p.end());
        ull ans=1;
        /*for(auto i:p)
        {
            cout<<i.fi<<" "<<i.se<<endl;
        }*/
        ll count1=1;
        vll cnt;
        rep(i,p.size()-1)
        {
            if(p[i]==p[i+1])
            count1++;
            else
            {
                if(count1!=1)
                cnt.pb(count1);
                count1=1;
            }

            if(i==(p.size()-2)&&count1!=1)
                cnt.pb(count1);
        }
        //cout<<ans<<" "<<count<<" "<<count2<<endl;
        /*for(auto f:cnt)
        {
            cout<<f<<" ";
        }
        //cout<<endl;*/
        ans=fac[count3];
        //cout<<ans<<endl;
        rep(i,cnt.size())
        {
            ans*=power((ull)fac[cnt[i]],(ull)MOD-2,(ull)MOD);
            ans%=MOD;
        }
        for(int i=1;i<=(count3-count2);i++)
        {
            ans*=2;
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
}
/*
e f
e f
a b
a b
24*16/4
6+12+6+12+24+12+6+12+6


a a
a a
c d
c d 24*16/4*4

6+12+6
*/