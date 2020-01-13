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
const int MAX_CHAR = 26; 
  
struct Trie { 
  
    // 'index' vectors size is greater than  
    // 0 when node/ is a leaf node, otherwise 
    // size is 0; 
    vector<int> index; 
  
    Trie* child[MAX_CHAR]; 
  
    /*to make new trie*/
    Trie() 
    { 
        // initializing fields 
        for (int i = 0; i < MAX_CHAR; i++) 
            child[i] = NULL; 
    } 
}; 
  
// function to insert a string in trie 
void insert(Trie* root, string str, int index) 
{ 
    Trie* node = root; 
  
    for (int i = 0; i < str.size(); i++) { 
  
        // taking ascii value to find index of 
        // child node 
        char ind = str[i] - 'a'; 
  
        // making a new path if not already 
        if (!node->child[ind]) 
            node->child[ind] = new Trie(); 
  
        // go to next node 
        node = node->child[ind]; 
    } 
  
    // Mark leaf (end of string) and store 
    // index of 'str' in index[] 
    (node->index).push_back(index); 
} 
  int k=0;
// function for preorder traversal of trie 
string* preorder(Trie* node, string arr[],int n,string brr[]) 
{ 
    // if node is empty 
    
    if (node == NULL) 
        return brr; 
  
    for (int i = 0; i < MAX_CHAR; i++) { 
        if (node->child[i] != NULL) { 
  
            // if leaf node then print all the strings 
            // for (node->child[i]->index).size() > 0) 
            for (int j = 0; j < (node->child[i]->index).size(); j++) 
                brr[k++]= arr[node->child[i]->index[j]]; 
  
            preorder(node->child[i], arr,n,brr); 
        } 
    } 
} 
  
// function to sort an array 
// of strings using Trie 
string* printSorted(string arr[], int n,string brr[]) 
{ 
    Trie* root = new Trie(); 
  
    // insert all strings of dictionary into trie 
    for (int i = 0; i < n; i++) 
        insert(root, arr[i], i); 
  
    // print strings in lexicographic order 
    return preorder(root, arr,n,brr); 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin.ignore(256,'\n');
        k=0;
        int n;
        cin>>n;
        string arr[n];
        string brr[n];
        rep(i,n)
        {
            cin>>arr[i];
        }
        printSorted(arr, n,brr);
        /*rep(i,n)
        {
            cout<<brr[i]<<endl;
        }*/
        int j=n/2;
        ll ans=0;
        rep(i,j)
        {
            int x=2*i;
            int l=min(brr[x].length(),brr[x+1].length());
            int f=0;
            rep(t,l)
            {
                if(brr[x][t]==brr[x+1][t])
                f++;
                else
                {
                    ans+=(f*f);
                    break;
                }
                
            }
        }
        cout<<ans<<endl;
    }
}