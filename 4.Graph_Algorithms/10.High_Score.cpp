#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))
#define Inf 1e18

//Bellman ford algorithm single source shortest path

void dfs(vector<int> g[], vector<bool> &visited, int u){
	visited[u]=true;
	for(int v : g[u]){
		if(!visited[v]){
			dfs(g, visited, v);
		}
	}
}

void solve(){
	int n, m;
	cin>>n>>m;
	vector<ar<ll, 3>> edges(m);
	vector<int> rev_graph[n];
	vector<int> graph[n];
	vector<bool> visited(n, false);
	vector<bool> visited2(n, false);
	for(int i=0;i<m;i++){
		int a, b, c;
		cin>>a>>b>>c;
		edges[i][0] = a-1;
		edges[i][1] = b-1;
		edges[i][2] = c;
		rev_graph[b-1].push_back(a-1);
		graph[a-1].push_back(b-1);
	}

	dfs(rev_graph, visited, n-1);
	dfs(graph, visited2, 0);
	
	ll dist[n];
	for(int i=0;i<n;i++){
		dist[i]=-Inf;
	}
	dist[0]=0;

	for(int i=1;i<=n-1;i++){
		for(ar<ll, 3> edge :edges){
			ll u = edge[0];
			ll v = edge[1];
			ll w = edge[2];
			if(dist[u] + w > dist[v])
				dist[v] = dist[u] + w;
		}
	}

	int flag=0;
	for(ar<ll, 3> edge :edges){
		ll u = edge[0];
		ll v = edge[1];
		ll w = edge[2];
		if(dist[u] + w > dist[v]){
			if(visited[v] && visited2[v]){
				flag=1;
			}
			dist[v] = dist[u] + w;
		}
	}

	// for(int i=0;i<n;i++){
	// 	cout<<i<<" : ";
	// 	for(int v : rev_graph[i]){
	// 		cout<<v<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	// for(int i=0;i<n;i++){
	// 	cout<<visited[i]<<" ";
	// }
	// cout<<"\n";

	if(flag){
		cout<<"-1\n";
		return;
	}
	
	cout<<dist[n-1]<<"\n";
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}