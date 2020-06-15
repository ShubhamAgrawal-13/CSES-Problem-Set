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
    ll sum_n=n*(n+1)/2;
    ll sum=0;
    for(int i=1;i<n;i++)
    {
        int a=0;
        cin>>a;
        sum+=a;
    }
    print(sum_n-sum);
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

//Approach:
//XOR has certain properties

//    Assume a1 ^ a2 ^ a3 ^ …^ an = a and a1 ^ a2 ^ a3 ^ …^ an-1 = b
//    Then a ^ b = an
