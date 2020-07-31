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

void solve(){
    int n,k;
    cin>>n>>k;

    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    ll low = *max_element(all(a));
    ll high = 1e18;

    while(low<high){
        ll mid = low + (high-low)/2;

        int c=1;
        ll sum=0;

        for(int i=0;i<n;i++){
            if(sum+a[i]>mid){
                c++;
                sum=0;
            }
            sum+=a[i];
        }

        if(c>k)
            low=mid+1;
        else
            high=mid;
    }
    cout<<low<<"\n";
	
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