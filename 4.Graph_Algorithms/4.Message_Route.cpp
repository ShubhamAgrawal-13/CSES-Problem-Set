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
#define clr(x) memset(x,0,sizeof(x))

vector<int> a[MAX];
vector<int> res;
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

void solve()
{
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
	clr(visited);
	clr(parent);

	int src=1;
	int dest=n;

	queue<int> q;
	q.push(src);
	visited[src]=true;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		//deb(u);
		for(int v : a[u]){
			if(visited[v]==false){
				visited[v]=true;
				parent[v]=u;
				q.push(v);
			}
		}
	}
	int nn = dest;
	while(nn){
		res.pb(nn);
		nn=parent[nn];
	}
	reverse(all(res));

	if(res.size()>1){
		cout<< res.size()<<"\n";
		for (int i = 0; i < res.size(); ++i)
		{
			cout<< res[i] << " ";
		}
		cout<<"\n";
	}	
	else{
		cout<<"IMPOSSIBLE\n";
	}
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