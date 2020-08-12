#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))
#define Inf 1e18

void solve(){
	int n, m;
	cin>>n>>m;

	vector<ar<ll, 3> > edges(m);

	for(int i=0;i<m;i++){
		int a, b ,c;
		cin>>a>>b>>c;
		edges[i][0] = a-1;
		edges[i][1] = b-1;
		edges[i][2] = c;
	}

	vector<ll> dist(n, Inf);
	vector<ll> parent(n, -1);
	dist[0]=0;
	vector<bool> vis(n, false);

	for(int i=0;i<n;i++){
		for(ar<ll, 3> edge : edges){
			ll u = edge[0];
			ll v = edge[1];
			ll w = edge[2];

			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				parent[v] = u;

				if(i==n-1){
					cout<<"YES\n";
					vector<int> ans;
					while(!vis[u]){
						vis[u]=1;
						u=parent[u];
					}
					ll p = u;
					ans.push_back(u+1);
					u =parent[u];

					while(p^u){
						ans.push_back(u+1);
						u = parent[u];
					}

					ans.push_back(u+1);
					reverse(all(ans));
					for(int aa : ans)
						cout<<aa<<" ";
					cout<<"\n";	
					return;

				}
			}
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout<<dist[i]<<" ";
	// }
	// cout<<"\n";
	// for(int i=0;i<n;i++){
	// 	cout<<parent[i]<<" ";
	// }
	// cout<<"\n";
	cout<<"NO\n";
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}