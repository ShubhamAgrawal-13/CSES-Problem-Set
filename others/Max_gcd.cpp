#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

void print_array(int array[], int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int prime[MAX];

void sieve()
{
    memset(prime,0,sizeof(prime));

    prime[0]=0;
    prime[1]=1;

    for (int p=2; p*p<=1000002; p++)
    {
        if(prime[p]==0)
        {
            //primes.push_back(p);
            for(int i=p*p; i<=1000002; i+=p)
            {
                if(prime[i]==0)
                    prime[i]=p;
            }
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

void solve()
{
    int n;
    cin>>n;


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