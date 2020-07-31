#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define vvl vector<vector<ll> >
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

void multiply(vvl &a, vvl &b){
    vvl c(2,vector<ll>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                c[i][j]=((c[i][j]+a[i][k]*b[k][j])%mod+mod)%mod;
            }
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            a[i][j]=c[i][j];
        }
    }
}

// 0 1  *  0 1  = 1 1
// 1 1     1 1  = 1 2

// n-1 n        n  n+1
// n   n+1      n+1 n+2

void solve(){
    ll n;
    cin>>n;

    vvl a(2,vector<ll>(2,0));
    vvl result(2,vector<ll>(2,0));
    a[0][1]=a[1][0]=a[1][1]=1;
    result[0][0]=result[1][1]=1;

    // if(n==0){
    //     cout<<"0\n";
    //     return;
    // }

    while (n > 0) {
        if (n & 1) 
            multiply(result,a);
        multiply(a,a);
        n >>= 1;
        //deb(a[0][0]);
    }
    cout<< result[0][1] <<"\n";
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