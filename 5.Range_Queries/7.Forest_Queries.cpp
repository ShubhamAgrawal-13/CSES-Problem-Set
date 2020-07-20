#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005
#define ll long long

//Hint go to Resources folder and open matrix_or_forest.png image 

int main(){
	int n,q;
	cin>>n>>q;
	char a[n][n];
	int dp[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}

	if(a[0][0]=='*')
		dp[0][0]=1;
	else
		dp[0][0]=0;

	for(int i=1;i<n;i++){
		if(a[0][i]=='*')
			dp[0][i]=1+dp[0][i-1];
		else
			dp[0][i]=dp[0][i-1];
	}

	for(int i=1;i<n;i++){
		if(a[i][0]=='*')
			dp[i][0]=1+dp[i-1][0];
		else
			dp[i][0]=dp[i-1][0];
	}


	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[i][j]=='*'){
				dp[i][j]=1+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			}else{
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			}
		}
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	while(q--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1--;
		x2--;
		y1--;
		y2--;

		if(x1==0 && y1==0){
			cout<<dp[x2][y2]<<"\n";
		}
		else if(x1==0 && y1!=0){
			cout<<dp[x2][y2]-dp[x2][y1-1]<<"\n";
		}
		else if(x1!=0 && y1==0){
			cout<<dp[x2][y2]-dp[x1-1][y2]<<"\n";
		}
		else{
			cout<<dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]<<"\n";
		}
	}

	return 0;
}