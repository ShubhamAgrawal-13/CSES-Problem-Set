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

int divisors[MAX];

// count divisors +=1
// sum of divisors +=i
// min divisor =i && divisor[i]==1 (prime divisor)
// max divisor similarly taken max prime divisor

void pre_process(){

    clr(divisors);

    for(int i=1;i<MAX;i++){
        for(int j=i;j<MAX;j+=i){
            divisors[j]+=1;
        }
    }

}

void solve()
{
    int n;
    cin>>n;
    cout<<divisors[n]<<endl;
} 

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
    
    int t=1;  
    cin>>t;  
    //sieve();
    pre_process();
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 