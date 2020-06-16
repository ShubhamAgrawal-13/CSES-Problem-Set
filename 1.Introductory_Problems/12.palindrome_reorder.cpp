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

    //int n = s.length();
    vector<int> a(26,0);

    for(char ch : s)
    {
        a[ch-'A']++;
    }
    int flag=0;
    int it=-1;
    for(int i=0;i<26;i++)
    {
        if(a[i]&1)
        {
            flag++;
            it=i;
        }
    }
    if(flag==0 || flag==1)
    {
        for(int i=0;i<26;i++)
        {
            if(it!=i)
            {
                for(int j=0;j<a[i]/2;j++)
                {
                    cout<<(char)('A'+i);
                }
            }
        }
        if(flag==1)
        {
            for(int j=0;j<a[it];j++)
            {
                cout<<(char)('A'+it);
            }
        }
        for(int i=25;i>=0;i--)
        {
            if(it!=i)
            {
                for(int j=0;j<a[i]/2;j++)
                {
                    cout<<(char)('A'+i);
                }
            }
        }
        cout<<"\n";
    }
    else
    {
        print("NO SOLUTION");
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