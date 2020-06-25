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

int dp[MAX];

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
    for(int i=0;i<=n;i++){
        dp[i]=INF;
    }
    dp[0]=0;
    for(int i=1;i<10;i++){
        dp[i]=1;
    }

    for(int i=10;i<=n;i++){
        int temp=i;
        int min=INF;
        while(temp>0){
            if(min > dp[i-temp%10]){
                min=dp[i-temp%10];
            }
            temp=temp/10;
        }
        dp[i]=1+min;
    }
    //print_array(dp,n);
	print(dp[n]);
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