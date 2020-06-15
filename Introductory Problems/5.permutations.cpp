#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

void solve()
{
	int n;
    cin>>n;

    if(n==2 || n==3)
        print("NO SOLUTION");

    else
    {
        for(int i=2;i<=n;i+=2)
        {
            cout<<i<<" ";
        }
        for(int i=1;i<=n;i+=2)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
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