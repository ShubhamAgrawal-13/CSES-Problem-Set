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

int factors(int n)
{
    int f=0;
    int root_n = ceil(sqrt(n)); 
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            //cout<<i<<" "<<n/i<<" ";
            f+=2;
        }
    }
    if(root_n*root_n == n)
    {
        f--;
    }
    return f;
}

/*


for d = 1..10^5
  for i = 1..10^5/d
    sumCnt += cnt[i * d]
  if (sumCnt >= 2) ans = max(ans, d)


*/

//https://www.hackerrank.com/contests/w34/challenges/maximum-gcd-and-sum
// hacker rank maximum gcd and sum
//one solutiom is O(n*sqrt(max))
// this solution is nearly O(n*log(n))
int find_max_gcd(vector<int> &a, int n){
    int high = *max_element(all(a));
    int count[high+1]={0};

    for(int i=0;i<n;i++)
        count[a[i]]++;

    int counter=0;
    for(int i=high;i>=1;i--){
        int j=i;
        counter=0;
        while(j<=high){
            if(count[j]>=2)
                return j;
            else if(count[j]==1)
                counter++;

            j+=i;
            if(counter==2)
                return i;
        }
    }
    return -1;
}

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<find_max_gcd(a,n)<<"\n";
} 

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    // cin>>t;  
    //sieve();
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 