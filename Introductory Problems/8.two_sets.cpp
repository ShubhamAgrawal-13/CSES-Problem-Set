#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

void solve()
{
    ll n;
    cin>>n;
	ll sum=0;
    sum=n*(n+1)/2;

    if(sum%2==0)
    {
        vector<int> set1;
        vector<int> set2;
        print("YES");
        sum/=2;

        while(n>0)
        {
            if(sum-n >= 0)
            {
                set1.push_back(n);
                sum-=n;
            }
            else
            {
                set2.push_back(n);
            }
            n--;
        }

        print(set1.size());
        for (int i = 0; i < set1.size(); ++i)
        {
            cout<<set1[i]<<" ";
        }
        print("");

        print(set2.size());
        for (int i = 0; i < set2.size(); ++i)
        {
            cout<<set2[i]<<" ";
        }
        print("");

    }
    else
    {
        print("NO");
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