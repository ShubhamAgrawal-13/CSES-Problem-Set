#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))

void solve(){
	int n, a, b;
	cin>>n>>a>>b;
	double dp[n+1][6*n+1];
	clr(dp, 0);
	dp[0][0]=1;
	for(int i=1; i<=n; i++){
		for(int j=i;j<=i*6;j++){
			for(int k=1;k<=6;k++){
				if(j-k>=0){
					dp[i][j]+=dp[i-1][j-k]/6;
				}
			}
		}  
	}
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=6*n;j++){
	// 		cout<<fixed<<setprecision(6)<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	double result = 0;
	for(int i=a;i<=b;i++)
		result += dp[n][i];
	cout<<fixed<<setprecision(6)<<result<<"\n";
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}