#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define print(x) cout << x << "\n"

ll inf=1e18;

// Dijkstra’s Shortest Path Algorithm

int main(){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

	int n,m;
	cin>>n>>m;
	vector<pair<ll,int>> graph[n];
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u-1].push_back({w,v-1});
	}

	// https://www.geeksforgeeks.org/implement-min-heap-using-stl/ 
    priority_queue< pair<ll,int>, vector <pair<ll,int>> , greater<pair<ll,int>> > pq; 

    vector<ll> dist(n,inf);
    dist[0]=0;
    pq.push({0,0});

    while(!pq.empty()){
    	auto front = pq.top();
    	int u = front.second;
    	pq.pop();

    	if(front.first > dist[u]){ // very important line
    		continue;
    	}

    	for(auto p : graph[u]){
    		int v = p.second;
    		ll w = p.first;

    		if(dist[v]>dist[u]+w){
    			dist[v]=dist[u]+w;
    			pq.push({dist[v],v});
    		}
    	}
    }

    for(ll d : dist){
    	cout<<d<<" ";
    }

    cout<<"\n";

	return 0;
}