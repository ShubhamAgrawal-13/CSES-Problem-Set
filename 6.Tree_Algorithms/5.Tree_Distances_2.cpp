#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 200005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define print(x) cout << x << "\n"

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x,v) memset(x,v,sizeof(x))

#define ar array 

void print_array(int array[], int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}

int mpow(int base, int exp) {

  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

int gcd(int a,int b){

	if(b==0)
		return a;
	return gcd(b,a%b);
}



vector<int> graph[MAX];
ll dp[MAX];
ll subTree[MAX];
int nodes[MAX];
int N;

void print_graph(int n){
    for(int i=1;i<=n;i++){
        cout<< i <<" : ";
        for(int j : graph[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

void dfs(int u, int p, ll par_sum){
    dp[u]=subTree[u]+par_sum+(N-nodes[u]);
    for(int v : graph[u]){
        if(v!=p){
            ll partial = dp[u] - (subTree[v]+nodes[v]);
            dfs(v,u,partial);
        }
    }
}

void sub_tree_sum(int u, int p){
    subTree[u]=0;
    bool leaf=1;
    for(int v : graph[u]){
        if(v!=p){
            leaf=0;
            sub_tree_sum(v,u);
        }
    }
    if(leaf)
        return;
    ll sum=0;
    for(int v : graph[u]){
        if(v!=p){
            sum+=subTree[v]+nodes[v];
        }
    }
    subTree[u]+=sum;
}



void num_nodes(int u, int p){
    nodes[u]=1;
    bool leaf=1;
    for(int v : graph[u]){
        if(v!=p){
            leaf=0;
            num_nodes(v,u);
        }
    }
    if(leaf)
        return;
    int sum=0;
    for(int v : graph[u]){
        if(v!=p){
                sum+=nodes[v];
        }
    }
    nodes[u]+=sum;
}

void solve(){
    int n;
    cin>>n;	
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    //print_graph(n);
    clr(dp,0);
    num_nodes(1,0);
    sub_tree_sum(1,0);
    N=nodes[1];
    dfs(1,0,0);
    for(int i=1;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<"\n";
}

int main(int argc, char const *argv[])  {

    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    //cin>>t;  
  
    while(t--) {  
        solve();
    }  
  
    return 0;  
} 