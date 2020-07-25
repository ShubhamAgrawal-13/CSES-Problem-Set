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
int dist[MAX];
bool visited[MAX];

void print_graph(int n){
    for(int i=1;i<=n;i++){
        cout<< i <<" : ";
        for(int j : graph[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

int bfs(int u, int n){
    queue<int> q;
    q.push(u);
    dist[u]=0;
    visited[u]=true;

    while(!q.empty()){
        int u2 = q.front();
        q.pop();

        for(int v : graph[u2]){
            if(visited[v]==false){
                dist[v]=dist[u2]+1;
                visited[v]=true;
                q.push(v);
            }
        }
    }
    int max_index=0;
    int max_value=0;

    for(int i=1;i<=n;i++){
        if(max_value<dist[i]){
            max_index=i;
            max_value=dist[i];
        }
    }

    return max_index;
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
    clr(dist,0);
    clr(visited,0);
    int f=bfs(1,n);
    clr(dist,0);
    clr(visited,0);
    int f2=bfs(f,n);
    cout<<dist[f2]<<"\n";
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