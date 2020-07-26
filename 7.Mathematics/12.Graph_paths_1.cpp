#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
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

//Matrix Exponentiation

void multiply(vector<vector<ll> > &a, vector<vector<ll> > &b, int n){
    vector<vector<ll> > c(n,vector<ll>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=c[i][j];
}

void matrix_exp(vector<vector<ll>> &graph,vector<vector<ll>> &result, int n, int e){
    while(e>0){
        if(e&1){
            multiply(result,graph,n);
        }
        multiply(graph,graph,n);
        e>>=1;
    }
}

void solve(){
	int n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll> > graph(n,vector<ll>(n,0)); 
    vector<vector<ll> > result(n,vector<ll>(n,0)); 
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a-1][b-1]++;
    }
    for(int i=0;i<n;i++)
        result[i][i]=1;
    matrix_exp(graph, result, n, k);

    cout<<result[0][n-1]<<"\n";
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