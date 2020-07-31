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

ll digit_dp[20][200][200][2];
int postion[20];
bool prime[200];


ll get_count(int pos, int n, int sum, int xorr, int flag){
     if(pos>=n){
        if((xorr==1) && !prime[sum]){
            // cout<<sum<<" ";
            return 1;
        }
        return 0;
     }

     if(digit_dp[pos][sum][xorr][flag]!=-1)
          return digit_dp[pos][sum][xorr][flag];

     int limit = 9;
     if(!flag)
          limit=postion[pos];

     ll res=0;
     for(int i=0;i<=limit;i++){
          if(flag || i<limit)
               res += get_count(pos+1, n, sum+i, xorr^i, true);
          else
               res += get_count(pos+1, n, sum+i, xorr^i, false);
     }

     return digit_dp[pos][sum][xorr][flag]=res;
}


bool isPrime(int n){
    if(n<2)
        return false;
    if(n<=3)
        return true;

    if(!(n%2) || !(n%3))
        return false;

    for(int i=5;i*i<=n;i+=6){
        if(!(n%i) || !(n%(i+2)))
            return false;
    }

    return true;
}


void solve(){
     string a;
     cin>>a;
     int i=0;
     for(char ch : a){
          postion[i++]=ch-'0';
     }
     clr(digit_dp,-1);
     cout<<get_count(0,a.length(),0,0,0)<<endl;
} 

int main(int argc, char const *argv[])  {

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t; 
    clr(prime,0); 
    for(int i=2;i<200;i++){
        if(isPrime(i)){
            prime[i]=1;
            //cout<<i<<" ";
        }
    }
    //cout<<"\n";

  
    while(t--) {  
        solve();
    }  
  
    return 0;  
} 