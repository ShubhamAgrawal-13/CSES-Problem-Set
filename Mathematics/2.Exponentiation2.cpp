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

ll power(ll b, ll e)
{
	if(e==0)
        return 1;
    if(e==1)
        return b%mod;

    ll temp = power(b,e/2);
    temp=(temp*temp)%mod;
    if(temp<0)
        temp+=mod;
    if(e&1)
        return (b*temp)%mod;
    return temp%mod;
} 

int main(int argc, char const *argv[])  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  
    int t=1;  
    cin>>t;  
  
    while(t--)  
    {  
        ll a,b,c;
        cin>>a>>b>>c;
        ll p1 = power(b,c);
        if(p1<0)
            p1+=mod;
        p1=power(a,p1);
        if(p1<0)
            p1+=mod;
        cout<<p1<<endl;
    }  
  
    return 0;  
} 