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
/*
11111   11111
11111   13331
11111   13531
11111   13331
11111   11111
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int arr[n][m];
        rep(i,n)
        {
            rep(j,m)
            {
                cin>>arr[i][j];
            }
        }
        if(m==1||n==1)
        {
            cout<<m*n<<endl;
            continue;
        }
        int brr[n][m];
        int crr[n][m];
        //cout<<endl;
        rep(i,n)
        {
            int k=2*m+1;
            int l[k];
            l[0]=0;
            l[1]=1;
            brr[i][0]=l[1];
            int cenp=1;
            int cenrp=2;
            int curp;
            int culp;
            int expand;
            int diff;

            //cout<<l[1]<<" ";
            if(m==1)
            break;
            for(curp=2;curp<k;curp++)
            {
                culp=2*cenp-curp;
                expand=0;
                diff= cenrp-curp;
                //cout<<culp<<" "<<curp<<" "<<diff<<" "<<cenp<<endl;
                if(diff>0)
                {
                    if(l[culp]<diff)
                    l[curp]=l[culp];
                    else if(l[culp]==diff && curp==k-2)
                    l[curp]=l[culp];
                    else if(l[culp]==diff && curp < k-2)
                    {
                        l[curp]=diff;
                        expand=1;
                    }
                    else if(l[culp]>diff)
                    {
                        l[curp]=diff;
                        expand=1;
                    }
                }
                else
                {
                    l[curp]=0;
                    expand=1;
                }

                if(expand==1)
                {
                    while(((curp+l[curp])<k&&(curp-l[curp])>0)&& (((curp+l[curp]+1)%2==0)||(arr[i][(curp+l[curp]+1)/2]==arr[i][(curp-l[curp]-1)/2])))
                    l[curp]++;
                }
                if(curp+l[curp]>cenrp)
                {
                    cenp=curp;
                    cenrp=curp+l[curp];
                }
                if(curp%2==1)
                {
                    brr[i][curp/2]=l[curp];
                    //cout<<l[curp]<<endl;
                }

                
            }
            //cout<<endl;
            /*rep(j,m)
            {
                cout<<brr[i][j]<<" ";
            }
            cout<<endl;*/
        }
        //cout<<endl;
        rep(i,m)
        {
            int k=2*n+1;
            int l[k];
            l[0]=0;
            l[1]=1;
            crr[0][i]=l[1];
            int cenp=1;
            int cenrp=2;
            int curp;
            int culp;
            int expand;
            int diff;
            if(n==1)
            break;
            //cout<<l[1]<<" ";
            for(curp=2;curp<k;curp++)
            {
                culp=2*cenp-curp;
                expand=0;
                diff= cenrp-curp;
                //cout<<culp<<" "<<curp<<" "<<diff<<" "<<cenp<<endl;
                if(diff>0)
                {
                    if(l[culp]<diff)
                    l[curp]=l[culp];
                    else if(l[culp]==diff && curp==k-2)
                    l[curp]=l[culp];
                    else if(l[culp]==diff && curp < k-2)
                    {
                        l[curp]=diff;
                        expand=1;
                    }
                    else if(l[culp]>diff)
                    {
                        l[curp]=diff;
                        expand=1;
                    }
                }
                else
                {
                    l[curp]=0;
                    expand=1;
                }

                if(expand==1)
                {
                    while(((curp+l[curp])<k&&(curp-l[curp])>0)&& (((curp+l[curp]+1)%2==0)||(arr[(curp+l[curp]+1)/2][i]==arr[(curp-l[curp]-1)/2][i])))
                    l[curp]++;
                }
                if(curp+l[curp]>cenrp)
                {
                    cenp=curp;
                    cenrp=curp+l[curp];
                }
                if(curp%2==1)
                {
                    crr[curp/2][i]=l[curp];
                    //cout<<l[curp]<<endl;
                }  
            }
            //cout<<endl;
        }
        /*rep(i,n)
        {
            rep(j,m)
            {
                cout<<crr[i][j]<<" ";
            }
            cout<<endl;
        }*/
        ll ans=0;
        rep(i,n)
        {
            rep(j,m)
            {
                int x=min(brr[i][j],crr[i][j]);
                x=(x+1)/2;
                ans+=x;
            }
        }
        cout<<ans<<endl;
    }
}