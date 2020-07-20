#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define INF 999999999
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

void print_array(int array[], int n){
	for(int i=0;i<n;i++){
		cout<<array[i]<<" ";
	}
	cout<<"\n";
}

void solve()
{
    int n,m;
    cin>>n>>m;

    int dp[n][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }

    //fill();
    int x0;
    cin>>x0;
    if(x0==0){
        for(int j=0;j<=m;j++){
            dp[0][j]=1;
        }
    }
    else{
        dp[0][x0]=1;
    }

    for(int i=1;i<n;i++){
        int x;
        cin>>x;

        if(x==0){
            for(int j=1;j<=m;j++){
                for(int k : {j-1,j,j+1}){
                    if(k>=1 && k<=m)
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                }
            }
        }
        else{
            for(int k : {x-1,x,x+1}){
                if(k>=1 && k<=m)
                    dp[i][x]=(dp[i][x]+dp[i-1][k])%mod;
            }
        }
    }

    ll ans=0;
    for(int j=1;j<=m;j++){
        ans=(ans+dp[n-1][j])%mod;
    }

    cout<<ans<<"\n";


    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
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