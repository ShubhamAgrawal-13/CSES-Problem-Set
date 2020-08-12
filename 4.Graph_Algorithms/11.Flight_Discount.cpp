#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))

#define MAX 100005
#define pi ar<ll, 2>
const ll Inf = 1e18;

vector<ar<ll, 2>> g1[MAX]; 
vector<ar<ll, 2>> g2[MAX];

void dijkstra(int src, vector<ar<ll, 2>> g[], vector<ll> &dist){
	priority_queue <pi, vector<pi>, greater<pi>> pq;
	pq.push({0, src});
	dist[src]=0;
	while(!pq.empty()){
		ll u = pq.top()[1];
		ll w = pq.top()[0];

		pq.pop();

		if(w > dist[u]){
			continue;
		}

		for(pi p : g[u]){
			if(dist[u] + p[0] < dist[p[1]]){
				dist[p[1]]=dist[u]+p[0];
				pq.push({dist[p[1]], p[1]});
			}
		}

	}
}

void solve(){
	int n, m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int a, b, c;
		cin>>a>>b>>c;
		g1[a-1].push_back({c, b-1});
		g2[b-1].push_back({c, a-1});
	}

	vector<ll > dist1(n, Inf);
	vector<ll > dist2(n, Inf);
	
	dijkstra(0, g1, dist1);
	dijkstra(n-1, g2, dist2);

	ll ans = 1e18+5;

	for(int i=0;i<n;i++){
		for(ar<ll, 2> j : g1[i]){
			ans = min(ans, dist1[i] + dist2[j[1]] + j[0]/2);
		}
	}
	cout<<ans<<"\n";
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}