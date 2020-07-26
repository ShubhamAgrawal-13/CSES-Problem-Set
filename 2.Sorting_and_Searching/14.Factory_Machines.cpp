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

// Binary Search over products
void solve(){
    ll n,target;
    cin>>n>>target;
    vector<ll> v(n);

    ll max_value=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>max_value)
            max_value=v[i];
    }

    ll low = 0;
    ll high = target*max_value+1;
    
    while(low<high){
        ll mid = low + (high - low)/2;
        ll current_products = 0;

        for(ll value : v){
            //current_products += mid/value;
            current_products += min(mid/value,(ll)1e9);
        }
        //cout<<low<<" "<<high<<" "<<current_products<<"\n";
        if(current_products >= target){
            high = mid;
        }
        else{
            low=mid+1;
        }
    }
    cout<< low << endl;
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