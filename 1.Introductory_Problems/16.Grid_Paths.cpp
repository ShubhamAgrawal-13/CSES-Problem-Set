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

int grid[7][7];
int si=0,sj=0,ei=0,ej=6;
int ctn=0;

int xx[]={-1,0,1,0};
int yy[]={0,-1,0,1};
char dd[]={'L','U','R','D'};

bool isSafe(int x, int y){
    if(grid[x][y]==0 && x>=0 && x<7 && y>=0 && y<7){
        return true;
    }
    return false;
}


void path(string &temp,int i,int j){
    if(temp.length() > 48)
    {
        return;
    }
    if(i==ei && j==ej){
        if(temp.length() == 48){
            ctn++;
            cout<<ctn<<" "<<temp<<"\n";
        }
        
    }
    grid[i][j]=1;
    //cout<<i<<" "<<j<<"\n";
    for(int d=0;d<4;d++){
        int x=i+xx[d];
        int y=j+yy[d];
        if(isSafe(x,y)){
            
            temp.pb(dd[d]);
            path(temp,x,y);
            temp.pop_back();
        }
    }
    grid[i][j]=0;
}

void solve()
{
    // string s;
    // cin>>s;
    clr(grid);
    ctn=0;
    string temp;
    //grid[0][0]=1;
    path(temp,si,sj);
    cout<<ctn<<"\n";
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