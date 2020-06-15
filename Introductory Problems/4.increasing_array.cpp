#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

void solve()
{
	ll n;
    cin>>n;

    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll count=0;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i])
        {
            count+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    print(count);
} 

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t;  
  
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 