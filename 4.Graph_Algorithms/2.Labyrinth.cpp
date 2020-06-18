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

#define pii pair<int,int>

#define N 1002

int parent[N][N];
char a[N][N]; 

int xx[]={-1,0,1,0};
int yy[]={0,-1,0,1};
char dd[]={'U','L','D','R'};

int n,m;

int si,sj,ei,ej;

bool isSafe(int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<m && a[i][j]=='.')
    {
        return true;
    }
    return false;
}

void path(vector<char> &result)
{
    int ni = ei, nj = ej;
    while(ni!=si || nj!=sj)
    {
        //cout<<ni<<" "<<nj<<"\n";
        int pi=ni-xx[parent[ni][nj]];
        int pj=nj-yy[parent[ni][nj]];
        result.push_back(dd[parent[ni][nj]]);
        ni=pi;
        nj=pj;
    }
    reverse(result.begin(), result.end());
}

void solve()
{
    cin>>n>>m;
    memset(parent,-1,N*N);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin>>a[i][j];
            if(a[i][j]=='A')
            {
                si = i;
                sj = j;
            }
            if(a[i][j]=='B')
            {
                ei = i;
                ej = j;
                a[i][j]='.';
            }
        }
    }

    //bfs
    queue<pii> q;
    q.push({si,sj});
  
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        //cout<< "(" << p.first << ", " <<p.second <<")  ";
        for(int d = 0; d<4; d++)
        {
            int x = p.first + xx[d];
            int y = p.second + yy[d];

            if(isSafe(x,y))
            {
                a[x][y]='#';
                parent[x][y]=d;
                q.push({x,y});
            }
        } 
    }
    //cout<<parent[ei][ej]<<" ";
    if(parent[ei][ej]!=-1)
    {
        cout<< "YES\n";
        vector<char> result;
        path(result);
        cout<< result.size()<<"\n";
        for (int i = 0; i < result.size(); ++i)
        {
            cout<< result[i];
        }
        cout<<"\n";
    }
    else
        cout<< "NO\n";
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