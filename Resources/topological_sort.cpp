#include <bits/stdc++.h>  
using namespace std;  

#define PI 3.14159265358979323846  
#define EXP 2.71828 
#define N 200007
#define INF 10000000000000LL  
#define mod 1000000007  

#define ll long long  
#define dd double

#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)

#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << " "

#define mfor(i,a,b) for(int i = a; i < b; ++i) 
#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair
#define F first  
#define S second  

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

#define matrix(a,i,j,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++) cout<<a[][]<<" "; cout<<endl;}


int mpow(int base, int exp) 
{
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

void all_topological_sort_util(vi graph[],int n,bool visited[],vi &in_degree,vi &result)
{
	bool f=false;
	mfor(i,0,n)
	{
		if(in_degree[i]==0 && visited[i]==false)
		{
			visited[i]=true;
			result.pb(i);
			for(int v : graph[i])
			{
				in_degree[v]--;
			}
			all_topological_sort_util(graph,n,visited,in_degree,result);
			//backtrack
			visited[i]=false;
			result.erase(result.end()-1);
			for(int v : graph[i])
			{
				in_degree[v]++;
			}
			f=true;
		}
	}
	if(!f)
	{
		mfor(i,0,result.size())
		{
			print(result[i]);
		}
		cout<<endl;
	}
}


void all_topological_sort(vi graph[],int n)
{
	bool visited[n];
	clr(visited);
	vi in_degree(n,0);

	mfor(u,0,n)
	{
		for(int v : graph[u])
		{
			in_degree[v]++;
		}
	}

	vi result;
	all_topological_sort_util(graph,n,visited,in_degree,result);

}

void topological_sort_dfs_util(vi graph[],int n,bool visited[],vi &result,int u)
{
	visited[u]=true;

	for(int v : graph[u])
	{
		if(visited[v]==false)
		{
			topological_sort_dfs_util(graph,n,visited,result,v);
		}
	}

	result.pb(u);
}

void topological_sort_dfs(vi graph[],int n)
{
	bool visited[n];
	clr(visited);

	vi result; // we can also use stack and print result from top to bottom
	mfor(i,0,n)
	{
		if(visited[i]==false)
			topological_sort_dfs_util(graph,n,visited,result,i);
	}

	reverse(all(result));
	mfor(i,0,result.size())
	{
		print(result[i]);
	}
	cout<<endl;
}

void topological_sort(vi graph[],int n) //Kahn's Algorithm
{
	vi in_degree(n,0);
	vi result;
	mfor(u,0,n)
	{
		for(int v : graph[u])
		{
			in_degree[v]++;
		}
	}
	queue<int> q;
	mfor(i,0,n)
	{
		if(in_degree[i]==0)
			q.push(i);
	}
	int count1=0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		result.pb(u);
		for(int v : graph[u])
		{
			in_degree[v]--;
			if(in_degree[v]==0)
				q.push(v);
		}
		count1++;
	}
	if(count1!=n)
	{
		print("There exists cycle in graph\n");
		// exit(0);
		return;
	}
	mfor(i,0,result.size())
	{
		print(result[i]);
	}
	cout<<endl;
}

void solve()
{
	int n=6;
	vi graph[n];
	graph[5].push_back(2);
	graph[5].push_back(0);
	graph[4].push_back(0);
	graph[4].push_back(1);
	//graph[1].push_back(4);
	graph[2].push_back(3);
	graph[3].push_back(1);
	//topological_sort(graph,n);
	topological_sort_dfs(graph,n);
	//all_topological_sort(graph,n);
	
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


// import subprocess

// subprocess.call("date",shell='True')