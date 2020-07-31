#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define print(x) cout << x << "\n"

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x,v) memset(x,v,sizeof(x))

#define ar array 

void print_array(int array[], int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}

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

int gcd(int a,int b){

	if(b==0)
		return a;
	return gcd(b,a%b);
}


/*
As is typical with problems involving subarrays, 
we use prefix sums to add each subarray. 
Let P[i+1] = A[0] + A[1] + ... + A[i]. 
Then, each subarray can be written as 
P[j] - P[i] (for j > i). 
Thus, we have P[j] - P[i] equal to 0 modulo K, 
or equivalently P[i] and P[j] are the same value modulo K.
*/

/*
B = new array( K )
B[0]++
s = 0
for i = 0 to N - 1
  s = ( s + A[i] ) % K
  B[s]++
ans = 0
for i = 0 to K - 1
  ans = ans + B[i] * ( B[i] - 1 ) / 2

*/


void solve(){
	int n;
    cin>>n;

    map<ll,int> m;
    ll sum=0, ans=0;
    m[0]=1;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum=((sum+a)%n+n)%n; 
        ans+=m[sum];
        m[sum]++;
    }   
    cout<<ans<<"\n";
} 

int main(int argc, char const *argv[])  {

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t;  
  
    while(t--) {  
        solve();
    }  
  
    return 0;  
} 