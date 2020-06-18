#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

int mpow(int base, int exp) 
{
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}


ll fact[MAX];
void factorial()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<MAX-1;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
    }
}


void solve()
{
	ll n,k;
    cin>>n>>k;

    ll res=(((fact[n]*mpow(fact[k],mod-2))%mod * mpow(fact[n-k],mod-2))%mod)%mod;
    cout<<res<<endl;
} 

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    cin>>t;  
    factorial();
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 