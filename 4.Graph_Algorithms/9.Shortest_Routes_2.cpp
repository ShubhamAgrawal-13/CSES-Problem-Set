#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define print(x) cout << x << "\n"

ll inf=1e18;

// Floyd Warshall Algorithm All Pairs Shortest Path Algorithm

int main(){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

	int n,m,q;
	cin>>n>>m>>q;
    ll dist[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=inf;
        }
    }
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
        if(w<dist[u][v])
            dist[u][v]=w;
        if(w<dist[v][u])
            dist[v][u]=w;
	}
    
    //floyd_warshall

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    

    while(q--){
        int u,v;
        cin>>u>>v;
        if(dist[u][v]==inf)
            cout<<-1<<"\n";
        else
            cout<<dist[u][v]<<"\n";
    }

	return 0;
}