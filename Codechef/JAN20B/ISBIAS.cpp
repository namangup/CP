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
    int a[n];
    arrin(a,n);
    int b[n];
    int c[n];
    c[0]=0;
    b[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        if(a[i+1]>a[i])
        b[i]=1+b[i+1];
        else
        {
            b[i]=0;
        }
        //cout<<b[i]<<endl;    
    }
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i])
        c[i]=1+c[i-1];
        else
        {
            c[i]=0;
        }   
    }
    
    rep(i,n)
    cout<<b[i]<<" ";
    cout<<endl;
    rep(i,n)
    cout<<c[i]<<" ";
    cout<<endl;
    
    //03210210
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int x=0,y=0;
        for(int i=l-1;i<r;)
        {
            if(i==l-1&&b[i]!=0)
            {
                //cout<<i<<"1"<<endl;
                x++;
                i=i+b[i];
            }
            else if(b[i]==0&&i!=(r-1))
            {
                if(a[i+1]==a[i])
                {
                    if(b[i-1]!=0&&i>=l)
                    x--;
                    while((a[i+1]==a[i])&&i<(r-1))
                    i++;
                    if(i==(r-1))
                    break;
                }
                if(b[i+1]==0||i==(r-2))
                {
                    i++;
                    continue;
                }
                //cout<<i<<"2"<<endl;
                x++;
                i=i+1+b[i+1];
            }
            else if(i==(r-1))
            {
                break;
            }
        }
        if(x<0)
        x=0;
        //cout<<x<<endl;
        for(int i=r-1;i>=l-1;)
        {
            if(i==(r-1)&&c[i]!=0)
            {
                //cout<<i<<"1"<<endl;
                y++;
                i=i-c[i];
            }
            else if(c[i]==0&&i!=(l-1))
            {
                if(a[i-1]==a[i])
                {
                    if(c[i-1]!=0&&i>(l-1))
                    y--;
                    //cout<<y<<endl;
                    while((a[i-1]==a[i])&&i>(l-1))
                    i--;
                    //cout<<i<<endl;
                    if(i==(l-1))
                    break;
                }
                if(c[i-1]==0)
                {
                    i--;
                    continue;
                }
                //cout<<i<<"2"<<endl;
                y++;
                i=i-1-c[i-1];
            }
            else if(c[i]==0&&i==(l-1))
            {
                break;
            }
        }
        if(y<0)
        y=0;
        //cout<<y<<endl;
        if(x==y)
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
}
/*
1765
4156
3217
2341

1YX987
61YX78
5617X9
4521YX
32561Y
234561

12468X
31579Y
54
76
98
YX

13579Y
239Y75
4853Y7
6X2759
86X493
X4682Y

13579ABC
 3
  5
   7
    9
     A
      B
       C
*/