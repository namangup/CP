#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vll;



const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


#define      rep(i, n)         for(ll i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(int i = a; i <= (n); ++i)

#define mp make_pair
#define pb push_back
#define vin(a,n) rep(i,n){ll x;cin>>x;a.pb(x);}

ull power(ull x, ull y, ull p) 
{ 
    ull res = 1; 
    x = x % p;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
}
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}
int main()
{
    int t;
    fastRead_int(t);
    ull fac[100010];
    ull pow2[100010];
    fac[0]=1;
    pow2[0]=1;
    for(ll i=1;i<=100009;i++)
    {
        fac[i]=(fac[i-1]*i)%MOD;
        pow2[i]=(pow2[i-1]*2)%MOD;
    }
    rep(f,t)
    {
        int n;
        fastRead_int(n);
        vll a;
        ll s=0;
        rep(i,2*n)
        {
            int x;
            fastRead_int(x);
            a.pb(x);
            s+=a[i];
        }
        if(s%(n+1)!=0)
        {
            printf("0\n");
            continue;
        }
        ll k=s/(n+1);
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
            if(count==2)
            flag=1;
            if(!flag)
            {
                printf("0\n");
                continue;
            }
        }
        if(n==1)
        {
            printf("1\n");
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
        if(q.size()!=0)
        {
            printf("0\n");
            continue;
        }
        sort(p.begin(),p.end());
        ull ans=1;
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
        ans=fac[count3];
        rep(i,cnt.size())
        {
            ans*=power((ull)fac[cnt[i]],(ull)MOD-2,(ull)MOD);
            ans%=MOD;
        }
        ans*=pow2[count3-count2];
        ans%=MOD;
        printf("%d\n",ans);
    }
}