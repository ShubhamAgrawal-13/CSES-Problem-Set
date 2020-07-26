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

//Matrix Exponentiation beautiful variation

const ll inf=1e18;

void multiply(vector<vector<ll> > &a, vector<vector<ll> > &b, int n){
    vector<vector<ll> > c(n,vector<ll>(n,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){

                if(a[i][k]!=0 && b[k][j]!=0){ //->
                    if(c[i][j]==-1)
                        c[i][j]=a[i][k]+b[k][j];
                    else
                        c[i][j]=min(c[i][j],a[i][k]+b[k][j]);//->
                }
        
            }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(c[i][j]==-1) //->
                a[i][j]=0;
            else
                a[i][j]=c[i][j];
        }
}

void matrix_exp(vector<vector<ll>> &graph,vector<vector<ll>> &result, int n, int e){
    int flag=1;
    while(e>0){
        if(e&1){
            if(flag){
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        result[i][j]=graph[i][j]; //->
                flag=0;
            }
            else
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
        ll a,b,c;
        cin>>a>>b>>c;
        if(graph[a-1][b-1]==0)
            graph[a-1][b-1]=c;
        else
            graph[a-1][b-1]=min(graph[a-1][b-1],c); //->
    }
    for(int i=0;i<n;i++)
        result[i][i]=1;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<graph[i][j]<<" ";
    //     cout<<"------\n";
    // }

    matrix_exp(graph, result, n, k);

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<result[i][j]<<" ";
    //     cout<<"------\n";
    // }

    if(result[0][n-1]==0)
        cout<<"-1\n";
    else
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