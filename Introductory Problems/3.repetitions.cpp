#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

void solve()
{
    string s;
    cin>>s;
    int n = s.length();

    int j=0;
    int max=1;
    int l=1;
    for(int i=1;i<n;i++)
    {
        if(s[j]==s[i])
        {
            l++;
        }
        else
        {
            j=i;
            if(l>max)
                max=l;
            l=1;
        }
    }
    if(l>max)
        max=l;
    print(max);
} 

//Largest substring with same Characters
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