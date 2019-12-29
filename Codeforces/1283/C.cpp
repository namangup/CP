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
#define vin(a,n) rep(i,n){int x;cin>>x;a.pb(x);}
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
    int n;
    cin>>n;
    vi a;
    vin(a,n);
    int arr[n]={0};
    rep(i,n)
    {
        if(a[i]!=0)
        arr[a[i]-1]=1;
    }
    vi b;
    rep(i,n)
    {
        if(arr[i]==0)
        b.pb(i+1);
    }
    int k=0;
    rep(i,n)
    {
        if(a[i]==0)
        {
            if(b[k]==i+1)
            {
                int x=b[k];
                //cout<<x<<endl;
                
                b.erase(b.begin()+k);
                if(k!=b.size())
                b.pb(x);
                else
                {
                    b.insert(b.begin(),x);
                }
            }
            k++;
        }
    }
    k=0;
    rep(i,n)
    {
        if(a[i]==0)
        {
            a[i]=b[k++];
        }
        cout<<a[i]<<" ";
    }
}