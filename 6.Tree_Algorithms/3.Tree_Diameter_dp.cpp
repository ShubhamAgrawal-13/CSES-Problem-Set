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
int dp[MAX];
int depth[MAX];

void print_graph(int n){
    for(int i=1;i<=n;i++){
        cout<< i <<" : ";
        for(int j : graph[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

void dfs(int u, int p){
    dp[u]=0;

    bool leaf=1;

    for(int v : graph[u]){
        if(v!=p){
            leaf=0;
            dfs(v,u);
        }
    }

    if(leaf)
        return;

    vector<int> children;
    for(int v : graph[u]){
        if(v!=p){
            children.push_back(depth[v]);
        }
    }
    sort(all(children));
    if(children.size() >=2){
        dp[u]=2+children[children.size()-1]+children[children.size()-2];
    }

    if(children.size() ==1){
        dp[u]=1+children[children.size()-1];
    }

    for(int v : graph[u]){
        if(v!=p){
            dp[u]=max(dp[u],dp[v]);
        }
    }
}

void down_path(int u, int p){
    depth[u]=0;

    bool leaf=1;

    for(int v : graph[u]){
        if(v!=p){
            leaf=0;
            down_path(v,u);
        }
    }

    if(leaf)
        return;

    int max_child=0;
    for(int v : graph[u]){
        if(v!=p){
            if(depth[v] > max_child)
                max_child=depth[v];
        }
    }


    depth[u]=1 + max_child;
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
    down_path(1,-1);
    dfs(1,-1);
    cout<<dp[1]<<"\n";
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