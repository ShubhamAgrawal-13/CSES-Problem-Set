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

bool dp[2][100005];

//Subset sum problem
void solve()
{
    int n;
    cin>>n;
    int sum=0;
    int coins[n];

    for(int i=0; i<n; i++){
        cin>>coins[i];
        sum+=coins[i];
    }

    dp[0][0]=true;
    dp[1][0]=true;

    for(int j=1;j<=sum;j++){
        if(j==coins[0])
            dp[0][j]=true;
        else
            dp[0][j]=false;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(i&1){
                dp[1][j]=dp[0][j];
                if(j-coins[i]>=0)
                    dp[1][j] |= dp[0][j-coins[i]];  
            }
            else{
                dp[0][j]=dp[1][j];
                if(j-coins[i]>=0)
                    dp[0][j] |= dp[1][j-coins[i]];
            }
        }
    }

    int ans=(n+1)%2;
    int count=0;
    for(int i=1;i<=sum;i++){
        if(dp[ans][i])
            count++;
    }
    cout<<count<<"\n";
    for(int i=1;i<=sum;i++){
        if(dp[ans][i])
            cout<<i<<" ";
    }
    cout<<"\n";
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