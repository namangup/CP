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
#define vin(a,n) vi a;rep(i,n){int in;fri(in);a.pb(in);}
#define arrin(arr,n) rep(i,n){cin>>arr[i];}
#define vp(a) rep(i,a.size()){cout<<a[i]<<" ";}
#define fbo find_by_order
#define ook order_of_key
/*
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */
inline void fri(int &x) {
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
inline void frs(char *str)
{
    register char c = 0;
    register int i = 0;

    while (c < 33)
        c = getchar_unlocked();

    while (c != '\n') {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }

    str[i] = '\0';
}
int main()
{
    int n;
    vector<char> isp(n+1, true);
    isp[0] = isp[1] = false;
    for (int i = 2; i <= 1e5; i++) {
    if (isp[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= 1e5; j += i)
            isp[j] = false;
        }
    }
    int t;
    fri(t);
    while(t--)
    {
        int n,m;
        fri(n);
        fri(m);
        vi xp,xn,yp,yn;
        ll ans=0;
        rep(i,n)
        {
            int x;
            fri(x);
            if(x==0)
            ans+=(ll)(n-1)*m;
            else if(x>0)
            xp.pb(x);
            else
            {
                xn.pb(x);
            }
            
        }
        rep(i,m)
        {
            int x;
            fri(x);
            if(x==0)
            ans+=(ll)(m-1)*n;
            else if(x>0)
            yp.pb(x);
            else
            {
                yn.pb(x);
            }  
        }
        if(xp.size()<xn.size())
        xn.swap(xp);
        if(yp.size()<yn.size())
        yn.swap(yp);

        rep(i,xn.size())
        {
            
        }
    }
}