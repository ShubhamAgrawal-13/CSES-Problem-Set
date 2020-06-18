#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define MAX 1000005
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << endl
#define print(x) cout << x << endl

#define itr(i,v) for(auto i=v.begin();i!=v.end();i++) 

#define pb push_back
#define mp make_pair

#define all(v) v.begin(),v.end()
#define sortall(v) sort(all(v))
#define clr(x) memset(x,0,sizeof(x))

int xx[]={-1,0,1,0};
int yy[]={0,-1,0,1};

int n,m;

bool isSafe(int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<m)
    {
        return true;
    }
    return false;
}

void dfs(vector<vector<char>> &graph, int i, int j)
{
    graph[i][j]='#';
    //cout<<"("<<i<<","<<j<<")"<<" ";
    for(int d=0;d<4;d++)
    {
        int x = i + xx[d];
        int y = j + yy[d];

        if(isSafe(x,y) && graph[x][y]=='.')
        {
            dfs(graph,x,y);
        }
    }
}

void solve()
{
    cin>>n>>m;

    vector<vector<char>> graph(n,vector<char>(m,'#'));
    // vector<vector<bool>> visited(n,vector<bool>(m,false));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>graph[i][j];
        }
    }

    int count=0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(graph[i][j]=='.')
            {
                dfs(graph,i,j);
                //cout<<endl;
                count++;
            }
        }
    }
    cout<< count <<endl;
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