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

1 17 16 15 14 13 12 11 10
9 01 10 16 15 14 13 12 11
8 02 01 17 11 15 14 13 12
7 08 09 01 12 11 10 14 13
6 07 03 04 13 17 16 10 05
5 06 07 03 09
4 05 06 02 08
3 04 05 06 02
2 03 04 05 01
    */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        cout<<"Hooray\n1"<<endl;
        else if(n%2==1)
        cout<<"Boo"<<endl;
        else
        {
            cout<<"Hooray"<<endl;
            int brr[n-1][n/2][2];
            rep(i,n-1)
            {
                brr[i][0][0]=n-1;
                brr[i][0][1]=i;
                repA(j,1,n/2-1)
                {
                    brr[i][j][0]=(i+j)%(n-1);
                    brr[i][j][1]=(i-j+n-1)%(n-1);
                }
            }
            int arr[n][n];
            rep(i,n)
            arr[i][i]=1;
            rep(i,n-1)
            {
                rep(j,n/2)
                {
                    arr[brr[i][j][0]][brr[i][j][1]]=2+i;
                    arr[brr[i][j][1]][brr[i][j][0]]=n+1+i;
                }
            }
            rep(i,n)
            {
                rep(j,n)
                {
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        
    }
}