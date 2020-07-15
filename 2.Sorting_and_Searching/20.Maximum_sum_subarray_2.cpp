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
	int n,a,b;
    cin>>n>>a>>b;

    ll a[n];
    int flag=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=0)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<*max_element(a,a+n)<<endl;;
    }
    else
    {
        ll max=0,sum=0;

        for(int i=0;i<n;i++)
        {
            if(sum+a[i]>=0)
            {
                sum+=a[i];
                if(sum>max)
                    max=sum;
            }
            else
            {
                sum=0;
            }
        }

        cout<<max<<endl;
    }
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