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
    
    int dp[n+1][m+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=INT_MAX;
        }
    }

    for(int i=1;i<=n;i++){
        dp[i][1]=i-1;
    }    

    for(int i=1;i<=m;i++){
        dp[1][i]=i-1;
    }

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(i==j)
                dp[i][j]=0;
            else
            {
                for(int k=1;k<j;k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]+1);
                
                for(int k=1;k<i;k++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]+1);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<< dp[i][j] << " ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[n][m]<<"\n";
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