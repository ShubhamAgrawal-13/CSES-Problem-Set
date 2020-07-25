#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 200005
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x,v) memset(x,v,sizeof(x))

vector<int> a[MAX];
bool visited[MAX];
int parent[MAX];


void print_graph(int n){
	for(int i=1;i<=n;i++){
		cout<< i <<" : ";
		for(int j : a[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}

bool cyclic(int u,int p){
	visited[u]=true;
	parent[u]=p;
	//deb(u);
	for(int v : a[u]){
		if(!visited[v]){
			if(cyclic(v,u))
				return true;
		}
		else if(v!=p){
			int u1=u;
			// deb(u);
			// deb(v);
			vector<int> res;
			while(u^v){
				res.pb(u);
				u=parent[u];
			}
			res.pb(v);
			res.pb(u1);
			cout<<res.size()<<"\n";
			for(int k : res){
				cout<<k<<" ";
			}
			cout<<"\n";
			return true;
		}
	}
	return false;
}

//Detect cycle in an undirected graph
//https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
void solve() {
	int n,m;
	cin>>n>>m;

	for (int i = 1; i <=m ; ++i)
	{
		int x,y;
		cin>>x>>y;

		a[x].pb(y);
		a[y].pb(x);
	}

	//print_graph(n);
	clr(visited,0);
	clr(parent,-1);
	//bfs or dfs or set-union
	//dfs
	for(int i=1;i<=n;i++)
		if(!visited[i])
			if(cyclic(i,-1))
				return;
		
	cout<<"IMPOSSIBLE\n";
}

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t;  
  
    while(t--)  
    {  
        solve();
    }  
  
    return 0;  
} 