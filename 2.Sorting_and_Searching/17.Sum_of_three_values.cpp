#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define ar array


int main(){
	int n,x;
	cin>>n>>x;

	vector<ar<int,2>> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i][0];
		v[i][1]=i+1;
	}
	sort(v.begin(), v.end());
	for(int i=0;i<n-2;i++){
		int l = i+1;
		int r = n-1;

		while(l<r){
			if(v[l][0]+v[r][0]==x-v[i][0]){
				cout<<v[i][1]<<" "<<v[l][1]<<" "<<v[r][1]<<"\n";
				return 0; //Very Important
			}
			else if(v[l][0]+v[r][0]>x-v[i][0]){
				r--;
			}
			else{
				l++;
			}
		}
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}