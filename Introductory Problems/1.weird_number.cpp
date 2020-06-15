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

    while(n!=1)
    {
        cout<<n<<" ";
        if(n%2==0)
            n=n/2;
        else
            n=3*n+1;
    }
    cout<<1<<"\n";
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