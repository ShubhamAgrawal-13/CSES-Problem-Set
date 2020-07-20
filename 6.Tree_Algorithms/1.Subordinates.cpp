#include <bits/stdc++.h>  
using namespace std;

#define ll long long
#define MAX 200005
#define deb(x) cout << #x << "=" << x << "\n"

int a[MAX];

int dfs(vector<int> tree[],vector<int> &size,int p){
	if(tree[p].size()==0){
		return 0;
	}

	int sum=0;
	for(int i=0;i<tree[p].size();i++){
		size[tree[p][i]]=dfs(tree,size,tree[p][i]);
		sum+=1+size[tree[p][i]];
	}

	return sum;
}

int main(){
	int n;
	cin>>n;
	vector<int> tree[n+1];
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		tree[x].push_back(i);
	}
	vector<int> size(n+1,-1);
	size[1]=dfs(tree,size,1);	
	for(int i=1;i<=n;i++){
		cout<<size[i]<<" ";
	}
	cout<<endl;
	return 0;
}