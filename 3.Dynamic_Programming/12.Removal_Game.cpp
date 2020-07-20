#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

int main(){
	int n;
	cin>>n;

	int a[n];
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}

	//sum = score1 + score2
	//maximize score1 - score2

	// dp[l][r] = score1 - score2 in interval [l,r]
	vector<vector<ll>> dp(n,vector<ll>(n,0));

	for(int l=n-1; l>=0; l--){
		for(int r=l; r<n; r++){
			if(l==r){
				dp[l][r]=a[l];
			}
			else{
				dp[l][r]=max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
			}

		}
	}

	cout<< (sum+dp[0][n-1])/2<<"\n";

	// func(l,r,chance);

	// max(a[l]+func(l+1,r,(chance+1)%2), a[r]+func(l,r-1,(chance+1)%2));

	return 0;
}