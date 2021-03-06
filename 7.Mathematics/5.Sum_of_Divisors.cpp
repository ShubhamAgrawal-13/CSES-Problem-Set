#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define MAX 1000005
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

bool prime[MAX];
vector<int> primes;

void sieve()
{
    memset(prime,true,sizeof(prime));

    prime[0]=false;
    prime[1]=false;

    for (int p=2; p*p<=1000002; p++)
    {
        if(prime[p]==true)
        {
            //primes.push_back(p);
            for(int i=p*p; i<=1000002; i+=p)
                prime[i]=false;
        }
    }

    for (int p=2; p<=1000002; p++)
    {
        if(prime[p]==true)
        {
            primes.push_back(p);
            cout<<p<<" ";
        }
    }
    print(primes.size());
}

// n times O(sqrt(n))
int factors(ll n)
{
    ll sum=0;
    ll root_n = ceil(sqrt(n));

    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            //cout<<i<<" "<<n/i<<" ";
            sum=(sum+i)%mod;
            sum=(sum+n/i)%mod;
        }
    }

    if(root_n*root_n == n)
    {
        sum-=root_n;
    }
    return sum;
}

//Time complexity: O(n)
//Auxiliary space: O(1)

// void solve(){
//     ll n;
//     cin>>n;
//     //cout<<factors(n)<<endl;
//     ll sum=0;
//     for(int i=1;i<=n;i++){
//         sum=(sum+(n/i)*i)%mod;
//     }
//     cout<<sum<<"\n";
// } 

//O(log(n))

int mpow(int base, int exp) {

  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}


ll sum_n(ll n){
    ll nn=n;
    ll nn1=n+1;
    if(nn&1)
        nn1=nn1/2;
    else{
        nn=nn/2;
    }
    nn%=mod;
    nn1%=mod;
    return (nn*nn1)%mod;
}

ll range_sum(ll b, ll a){
    return (sum_n(b) - sum_n(a))%mod;
}

void solve(){
    ll n;
    cin>>n;
    ll result=0;

    ll i=1;

    while(1){
        ll  temp = range_sum(n/i, n/(i+1));
        ll  temp2 = ((temp%mod)*(i%mod))%mod;
        result += temp2;
        result%=mod;
        if(i==n)
            break;
        i= n/(n/(i+1));
    }

    cout<<result<<"\n";
} 

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t;  
    //sieve();
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 