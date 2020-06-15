#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))



bool shouldSwap(string &s, int start, int curr) 
{ 
    for (int i = start; i < curr; i++) 
        if (s[i] == s[curr]) 
            return 0; 
    return 1; 
} 

void permute(vector<string>& ans,string &s,int n,int p)
{
    if(p==n)
    {
        ans.push_back(s);
        return;
    }

    for(int i=p;i<n;i++)
    {
        if(shouldSwap(s,p,i))
        {
            swap(s[i],s[p]);
            permute(ans,s,n,p+1);
            swap(s[i],s[p]);
        }
    }
}

void solve()
{
    string s;
    cin>>s;
	vector<string> ans;
    int n = s.length();
    sort(s.begin(),s.end());
    permute(ans,s,n,0);
    print(ans.size());
    //sort
    sortall(ans);
    for(string str : ans)
    {
        print(str);
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