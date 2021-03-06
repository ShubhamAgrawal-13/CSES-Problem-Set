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
int color[MAX];


void print_graph(int n){
	for(int i=1;i<=n;i++){
		cout<< i <<" : ";
		for(int j : a[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}

// check if graph is bipartite or not
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

	//print_graph(a,n);
	clr(color,-1);
	
	//bfs
	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			queue<int> q;
			color[i]=1;
			q.push(i);

			while(!q.empty()){
				int u = q.front();
				q.pop();

				for(int v : a[u]){
					if(color[v]==-1){
						color[v]=1-color[u];
						q.push(v);
					}
					else if(color[u]==color[v]){
						cout<<"IMPOSSIBLE\n";
						return;
					}
				}
			}
		}
	}
	


	for(int i=1;i<=n;i++){
		if(color[i]==1){
			cout<<"1 ";
		}
		else{
			cout<<"2 ";
		}
	}
	
	cout<<"\n";
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