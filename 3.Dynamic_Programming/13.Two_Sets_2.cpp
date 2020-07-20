#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007

int main(){
	int n;
	cin>>n;
	int sum = n*(n+1)/2;
	if(sum&1){ //odd
		cout<<0<<"\n";
	}
	else{
		sum/=2;
		ll dp[n][sum+1];

		for(int i=0;i<n;i++)
			for(int j=0;j<=sum;j++)
				dp[i][j]=0;

		dp[0][0]=1;

		for(int i=1;i<n;i++){
			for(int j=0;j<=sum;j++){
				dp[i][j]=dp[i-1][j];
				if(j-i>=0){
					dp[i][j]=(dp[i][j]+dp[i-1][j-i])%mod;
				}
			}
		}
		cout<<dp[n-1][sum]<<"\n";
	}
	return 0;
}