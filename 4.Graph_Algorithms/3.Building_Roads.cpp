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


void print_graph(int n){
	for(int i=1;i<=n;i++){
		cout<< i <<" : ";
		for(int j : a[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}

void dfs(int u){
	//cout<<u<<" ";
	for(int v : a[u]){
		if(!visited[v]){
			visited[v]=true;  
			dfs(v);
		}
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
	//print_graph(a,n);
	clr(visited);
	
	for(int i=1;i<=n;i++)
	{
		if (visited[i]==false)
		{
			visited[i]=true;
			dfs(i);
			//cout<<"-----------\n";
			res.pb(i);
		}
	}

	cout<< res.size()-1<<"\n";
	for (int i = 1; i < res.size(); ++i)
	{
		cout<< res[i-1] << " " << res[i] <<"\n";
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