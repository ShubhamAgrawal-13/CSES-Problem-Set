#include <bits/stdc++.h>
using namespace std;

int xx[]={-1,0,1,0};
int yy[]={0,-1,0,1};

bool isSafe(int x,int y,int m, int n){
    if(x>=0 && x<m && y>=0 && y<n){
        return true;
    }
    return false;
}

int main() {
    int m,n;
    cin>>m>>n;
    // cout<<"hello";
    string graph[m];
    for(int i=0;i<m;i++){
        cin>>graph[i];
    }   
    //cout<<"hello3";
    
    int max=1;
    bool visited[m][n];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]=='1'){
                memset(visited,false,sizeof(visited));
                queue<pair<int, int>> q;
                int count=1;
                q.push({i,j});
                visited[i][j]=true;
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int d=0;d<4;d++){
                        int px=x+xx[d];
                        int py=y+yy[d];
                        
                        if(graph[px][py]=='1' && visited[px][py]==false && isSafe(px,py,m,n)){
                            q.push({px,py});
                            count++;
                            visited[px][py]=true;
                        }
                    }
                }
                
                if(count>max)
                    max=count;
            }
            
            if(graph[i][j]=='0'){
                graph[i][j]='1';
                memset(visited,false,sizeof(visited));
                queue<pair<int, int>> q;
                int count=1;
                q.push({i,j});
                visited[i][j]=true;
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int d=0;d<4;d++){
                        int px=x+xx[d];
                        int py=y+yy[d];
                        
                        if(graph[px][py]=='1' && visited[px][py]==false && isSafe(px,py,m,n)){
                            q.push({px,py});
                            count++;
                            visited[px][py]=true;
                        }
                    }
                }
                
                if(count>max)
                    max=count;

                graph[i][j]='0';
            }
        }
    }
    
    cout<<max<<"\n";
    return 0;
}
