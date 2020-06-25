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
    for(int i=0;i<=n;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

int dp[1001][100001];

//0-1 knapsack problem
void solve()
{
    int n,x;
    cin>>n>>x;

    int price[n];
    int pages[n];

    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    for(int i=0;i<n;i++){
        cin>>pages[i];
    }

    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }

    for(int j=1;j<=x;j++){
        if(j-price[0]>=0){
            dp[0][j]=pages[0];
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j-price[i]>=0){
                dp[i][j]=max(dp[i-1][j],pages[i]+dp[i-1][j-price[i]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    print(dp[n-1][x]);
    
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