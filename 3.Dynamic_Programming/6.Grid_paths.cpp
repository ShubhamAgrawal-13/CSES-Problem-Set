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

char grid[1001][1001];
ll dp[1001][1001];

void print_array(int array[], int n){
    for(int i=0;i<=n;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

void solve()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            dp[i][j]=0;
        }
    }

    if(grid[0][0]=='.')
        dp[0][0]=1;


    for(int i=1;i<n;i++){

        if(grid[i][0]=='.' && grid[i-1][0]=='.')
            dp[i][0]=dp[i-1][0];

        if(grid[0][i]=='.'&& grid[0][i-1]=='.')
            dp[0][i]=dp[0][i-1];

    }

    for(int i=1;i<n;i++){

        for(int j=1;j<n;j++){

            if(grid[i][j]== '.'){

                if(grid[i-1][j]=='.' && grid[i][j-1]=='.'){

                    dp[i][j]=(dp[i-1][j] % mod + dp[i][j-1] % mod)%mod;
                }

                else if(grid[i-1][j]=='.'){

                    dp[i][j]=dp[i-1][j] % mod ;
                }

                else if(grid[i][j-1]=='.'){

                    dp[i][j]=dp[i][j-1] % mod ;
                }
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    print(dp[n-1][n-1]);
    
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