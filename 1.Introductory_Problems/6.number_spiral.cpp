#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

ll entry(ll x, ll y)
{
    if(x>y)
    {
        if(x&1)
        {
            return (x-1)*(x-1)+1+y-1;
        }
        else
        {
            return x*x-y+1;
        }
    }
    else
    {
        if(y&1)
        {
            return y*y-x+1;
        }
        else
        {
            return (y-1)*(y-1)+1+x-1;
        }
    }
}

void solve()
{
	ll x,y;
    cin>>x>>y;
    cout<<entry(x,y)<<"\n";
    // for(int i=1;i<=9;i++)
    // {
    //     for(int j=1;j<=9;j++)
    //     {
    //         cout<<setw(3)<<entry(i,j)<<" ";
    //     }
    //     cout<<"\n";
    // }
} 

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    cin>>t;  
  
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 