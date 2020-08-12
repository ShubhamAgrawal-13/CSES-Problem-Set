#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))

void solve(){
	int n, k;
	cin>>n>>k;
	vector<int > a(k, 0);
	for(int i=0;i<k;i++)
		cin>>a[i];
	vector<bool > dp(n+1, false);
	dp[0]=false;

	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			if(i-a[j] >= 0){
				dp[i] = dp[i] | (!dp[i-a[j]]);
			}
		}
		(dp[i])?cout<<'W':cout<<'L';
	}
	cout<<"\n";
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}