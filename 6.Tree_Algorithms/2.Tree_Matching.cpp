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
int dp[MAX][2];

void print_graph(int n){
    for(int i=1;i<=n;i++){
        cout<< i <<" : ";
        for(int j : graph[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

void dfs(int u,int parent){

    vector<int> prefix;
    vector<int> suffix;
    dp[u][0]=0;
    dp[u][1]=0;

    int leaf=1;
    for(int v : graph[u]){
        if(v!=parent)
        {
            leaf=0;
            dfs(v,u);
        }
    }
    if(leaf) return;
    for(int v : graph[u]){  
        if(v!=parent){
            prefix.pb(max(dp[v][0],dp[v][1]));
            suffix.pb(max(dp[v][0],dp[v][1]));
        }
    }

    for(int i=1;i<prefix.size();i++){
        prefix[i]+=prefix[i-1];
    }

    for(int i=suffix.size()-2;i>=0;i--){
        suffix[i]+=suffix[i+1];
    }

    dp[u][0]=suffix[0]; 
    int c=0;
    for(int v : graph[u]){
        if(v!=parent){
            int p = (c==0)?0:prefix[c-1];
            int s = (c==suffix.size()-1)?0:suffix[c+1];
            dp[u][1]=max(dp[u][1] ,1 + p + dp[v][0] + s);
            c++;
        }
    }
    // deb(u);
    // deb(dp[u][0]);
    // deb(dp[u][1]);
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
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<"\n";
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