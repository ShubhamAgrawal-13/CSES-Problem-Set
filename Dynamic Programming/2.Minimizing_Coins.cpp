#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

void solve()
{
	int n,sum;
    cin>>n>>sum;

    int coin[n];
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }

    vector<int> dp(sum+1,9999999);
    dp[0]=0;
    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-coin[j]>=0)
            {
                dp[i]=min(dp[i],1+dp[i-coin[j]]);
            }
        }
    }
    // for(int d : dp)
    // {
    //     cout<<d<<" ";
    // }
    if(dp[sum]==9999999)
        print("-1");
    else
        print(dp[sum]);
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