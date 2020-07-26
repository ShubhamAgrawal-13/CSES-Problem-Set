#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define ar array

// mp.reserve(1<<20);

int main(){
	int n,x;
	cin>>n>>x;

	map<ll,pair<int,int>> m;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(m.find(x-v[i]-v[j])==m.end()){
				m[v[i]+v[j]]={i,j};
			}
			else{
				pair<int,int> p = m[x-v[i]-v[j]];

				if(p.first != i && p.first !=j && p.second != i && p.second !=j){
					cout<<i+1<<" "<<j+1<<" "<<p.first+1<<" "<<p.second+1<<"\n";
					return 0;
				}
			}
		}
	}


	
	cout<<"IMPOSSIBLE\n";
	return 0;
}