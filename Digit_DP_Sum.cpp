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

ll digit_dp[18][200][2];
int postion[20];

ll get_sum(int pos, int n, int sum, int flag){
     if(pos>=n)
          return sum;

     if(digit_dp[pos][sum][flag]!=-1)
          return digit_dp[pos][sum][flag];

     int limit = 9;
     if(!flag)
          limit=postion[pos];

     ll res=0;
     for(int i=0;i<=limit;i++){
          if(flag || i<limit)
               res += get_sum(pos+1, n, sum+i, true);
          else
               res += get_sum(pos+1, n, sum+i, false);
     }

     return digit_dp[pos][sum][flag]=res;
}



int digit_sum(string a){
     int res=0;

     for(char ch : a){
          res+=ch-'0';
     }

     return res;
}

int digit_sum_number(int n){
     int sum=0;
     while(n>0){
          sum+=n%10;
          n=n/10;
     }
     return sum;
}

void solve(){
     string a;
     cin>>a;
 //     ll res=0;
 //     int na = stoi(a);
 //     for(int i=1;i<=na;i++){
 //         res += digit_sum_number(i);
 //     }
	// cout<<"Digit Sum by Brute Force : "<<res<<endl;
     int i=0;
     for(char ch : a){
          postion[i++]=ch-'0';
     }
     clr(digit_dp,-1);
     cout<<"Digit Sum by Digit DP : "<<get_sum(0,a.length(),0,0)<<endl;

} 

int main(int argc, char const *argv[])  {

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    cin>>t;  
  
    while(t--) {  
        solve();
    }  
  
    return 0;  
} 