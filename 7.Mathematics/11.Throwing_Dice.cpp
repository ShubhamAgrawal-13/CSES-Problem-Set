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
    vvl c(6,vector<ll>(6,0));
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            for(int k=0;k<6;k++){
                c[i][j]=((c[i][j]+a[i][k]*b[k][j])%mod+mod)%mod;
            }
        }
    }

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            a[i][j]=c[i][j];
        }
    }
}

// 0 1  *  0 1  = 1 1
// 1 1     1 1  = 1 2

// n-1 n        n  n+1
// n   n+1      n+1 n+2

//Let f(n) be the number of ways of throwing dices 
//to get a sum of n, Then consider the last dice throw. 
//It has 6 possibilities 1-6. So f(n) = f(n-1) + f(n-2) + ... + f(n-6).
//https://www.geeksforgeeks.org/find-nth-term-a-matrix-exponentiation-example/


// t12    1 1 1 1 1 1   t11
// t11    1 0 0 0 0 0   t10  
// t10    0 1 0 0 0 0   t9
// t9     0 0 1 0 0 0   t8 
// t8     0 0 0 1 0 0   t7
// t7     0 0 0 0 1 0   t6

// t7     1 1 1 1 1 1   t6
// t6     1 0 0 0 0 0   t5  
// t5     0 1 0 0 0 0   t4
// t4     0 0 1 0 0 0   t3 
// t3     0 0 0 1 0 0   t2
// t2     0 0 0 0 1 0   t1

// t0=1
// t1=1
// t2=2
// t3=4   







void solve(){
    ll n;
    cin>>n;

    vector<ll> dp(7,0);
    dp[0]=1;

    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){  
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
        }
    }

    // if(n<=6){
    //     cout<<dp[n]<<"\n";
    //     return;
    // }

    // for(int i=0;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<"\n";

    vvl a(6,vector<ll>(6,0));
    for(int i=0;i<6;i++){
        a[0][i]=1;
    }
    for(int i=1;i<6;i++){
        a[i][i-1]=1;
    }

    vvl result(6,vector<ll>(6,0));
    for(int i=0;i<6;i++)
        result[i][i]=1;
   
    while (n > 0) {
        if (n & 1) 
            multiply(result,a);
        multiply(a,a);
        n >>= 1;
        //deb(a[0][0]);
    }
    ll ans=0;
    // for(int i=0;i<6;i++){
    //     for(int j=0;j<6;j++){
    //         cout<<result[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=0;i<6;i++)
    //     ans=(ans+result[5][i]*dp[6-i-1])%mod;
    // cout<< ans <<"\n";
    cout<< result[0][0] <<"\n";
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