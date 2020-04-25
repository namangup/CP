#include <bits/stdc++.h>
using namespace std;
#define pb push_back


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin>>n>>k;
    vector <int> arr(n);
    for(int i = 0; i<n; ++i)
        cin>>arr[i];
    /*int up = INT_MAX;
    vector<int> gone;
    gone.pb(arr[k-1]);
    int i = 0;
    sort(arr.begin, arr.end());
    while(i < gone.size())
    {
        bitset<32> ans = gone[i]^up;
    }*/
    vector<int> gone;
    gone.pb(arr[k-1]);
    int i = 0;
    arr.erase(arr.begin() + k-1);
    while(i<gone.size())
    {
        for(int j = 0; j < arr.size(); ++j)
        {
            if(arr[j]&gone[i])
            {
                gone.pb(arr[j]);
                arr.erase(arr.begin() + j);
                j--;
            }
        }
        i++;
    }
    //for(int j = 0; j < gone.size(); ++j)
    //cout<<gone[j]<<" ";
    cout<<arr.size();

}