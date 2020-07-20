#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define print(x) cout << x << "\n"

#define ar array
#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

int comp(const ar<ll, 3> &a,const ar<ll, 3> &b){
	return a[0]<b[0];
}


int main(){
	int n;
	cin>>n;
	vector<ar<ll,3>> projects(n);
	for(int i=0;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		projects[i][0]=b;
		projects[i][1]=a;
		projects[i][2]=c;
	}

	sortall(projects);
	vector<ll> dp(n+1,0);
	dp[0]=0;

	// for(int i=0;i<n;i++){
	// 	cout<<i<<": "<<projects[i][1]<<" "<<projects[i][0]<<" "<<projects[i][2]<<"\n";
	// }

	for(int i=1;i<=n;i++){
		ar<ll, 3> x={projects[i-1][1],0,0};
		int j = lower_bound(projects.begin(), projects.end(), x, comp)-projects.begin();
		j--;
		//deb(j);
		
		// deb(projects[i-1][2]+dp[j]);
		dp[i]=max(dp[i-1],projects[i-1][2]+dp[j+1]);
	}

	// for(int i=0;i<=n;i++){
	// 	cout<<dp[i]<<"\n";
	// }
	cout<<dp[n]<<"\n";

	return 0;
}