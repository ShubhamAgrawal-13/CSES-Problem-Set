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
int up[MAX][20];


void print_graph(int n){
    for(int i=1;i<=n;i++){
        cout<< i <<" : ";
        for(int j : graph[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

int dfs(int node, int x){
    if(node==-1 || x==0){
        return node;
    }
    for(int i=19;i>=0;i--){
        if(x>=(1<<i)){
            return dfs(up[node][i],x-(1<<i));
        }
    }
}

void binary_lifting(int u, int p){
    up[u][0]=p;
    for(int i=1;i<20;i++){
        if(up[u][i-1]==-1){
            up[u][i]=-1;
        }
        else{
            up[u][i]=up[up[u][i-1]][i-1];
        }
    }

    for(int v : graph[u]){
        if(v!=p){
            binary_lifting(v,u);
        }
    }

}

//Binary Lifting ( up array )

void solve(){
    int n,q;
    cin>>n>>q;	
    for(int i=2;i<=n;i++){
        int a=i,b;
        cin>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    //print_graph(n);
    binary_lifting(1,-1);

    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<dfs(a,b)<<"\n";
    }
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