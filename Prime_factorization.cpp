#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005

int prime[MAX];

void sieve(){
	for(int i=0;i<MAX;i++)
		prime[i]=0;

	for(int i=2;i*i<=MAX;i++){
		if(!prime[i]){
			for(int j=2*i;j<MAX;j+=i){
				if(!prime[j]){
					prime[j]=i;
				}
			}
		}
	}
	// int j=0;
	// for(int i=0;i<MAX;i++)
	// 	if(prime[i]==0)
	// 		cout<<++j<<" "<<i<<"\n";
}

//O(sqrt(N))
void prime_factor(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			int cnt=0;
			while(n%i==0){
				cnt++;
				n/=i;
			}
			cout<<"("<<i<<"^"<<cnt<<") ";
		}
	}
	if(n>1)
		cout<<"("<<n<<"^"<<1<<")\n";
	else
		cout<<"\n";
}

//O(logN)
void prime_factors(int n){
	map<int, int> mp;
	int nn=n;
	while(1){
		if(prime[nn]==0){
			mp[nn]++;
			break;
		}
		mp[prime[nn]]++;
		nn=nn/prime[nn];
	}
	for(auto i : mp){
		cout<<"("<<i.first<<"^"<<i.second<<") ";
	}
	cout<<"\n";
}

void solve(){
	int n;
	cin>>n;
	prime_factor(n);
	//prime_factors(n);
} 

int main(int argc, char const *argv[])  {

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  	sieve();
    int t=1;  
    //cin>>t;  
  
    while(t--) {  
        solve();
    }  
  
    return 0;  
}