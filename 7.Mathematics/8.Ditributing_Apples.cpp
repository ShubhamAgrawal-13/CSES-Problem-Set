#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 2000005
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


int nCr(int n, int k) 
{ 
    int res = 1; 
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
    // Calculate value of 
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (int i = 0; i < k; ++i) { 
        res *= (n - i); 
        res /= (i + 1); 
    } 
    return res; 
} 

void solve()
{
	int n,m;
    cin>>n>>m;
    int n1 = m + n - 1;
    int d1 = n - 1;
    int d2 = m;

    ll result=fact[n1]%mod;
    result=(result*mpow(fact[d1],mod-2)%mod)%mod;
    result=(result*mpow(fact[d2],mod-2)%mod)%mod;
    cout<<result<<"\n";
    //cout<< nCr(n1,d1)<<"\n"; //can't use because of dividing
} 

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    // cin>>t;  
    factorial();
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 








