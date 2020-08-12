#include <bits/stdc++.h>  
using namespace std;

#define ll long long 
#define mod 1000000007
#define deb(x) cout << #x << "=" << x << "\n"
#define ar array
#define all(v) v.begin(),v.end()
#define clr(x,v) memset(x,v,sizeof(x))

#define print_matrix(mat) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<mat[i][j]<<" ";}cout<<endl;}

#define MAX 1001
#define Inf 9999999

char graph[MAX][MAX];
int dist1[MAX][MAX], dist2[MAX][MAX], p1[MAX][MAX], p2[MAX][MAX];
bool vis[MAX][MAX];
int n, m;
ar<int, 2> start = {0,0};

bool isSafe(int i, int j){
	if(i>=0 && i<n && j>=0 && j<m && !vis[i][j])
		return 1;
	return 0;
}

int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};
int dc[]={'U', 'L', 'D', 'R'};

void bfs(vector<ar<int, 2>> v, int d[MAX][MAX], int p[MAX][MAX]){
	queue<ar<int, 2>> q;
	memset(vis, 0,sizeof(vis));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			d[i][j]=Inf;
	
	for(ar<int, 2> a : v){
		q.push(a);
		d[a[0]][a[1]]=0;
		vis[a[0]][a[1]]=1;
	}

	//print_matrix(d);
	while(!q.empty()){
		ar<int, 2> u = q.front();
		q.pop();

		for(int k=0; k<4; k++){
			ar<int, 2> nu = {u[0]+dx[k], u[1]+dy[k]};
			if(isSafe(nu[0], nu[1]) && graph[nu[0]][nu[1]]=='.'){
				vis[nu[0]][nu[1]]=1;
				d[nu[0]][nu[1]] = d[u[0]][u[1]] + 1;
				p[nu[0]][nu[1]] = k; 
				q.push(nu);
			}
		}
	}
}

void print_path(int i, int j){
	string ans;

	while(i^start[0] || j^start[1]){
		int k = p1[i][j];
		ans.push_back(dc[k]);
		i = i - dx[k];
		j = j - dy[k];
	}

	reverse(ans.begin(), ans.end());
	cout<<ans.length()<<"\n";
	cout<<ans<<"\n";
}

void solve(){
	cin>>n>>m;
	vector<ar<int, 2>> monsters;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>graph[i][j];
			if(graph[i][j]=='A'){
				start[0]=i;
				start[1]=j;
				graph[i][j]='.';
			}
			if(graph[i][j]=='M'){
				monsters.push_back({i, j});
				graph[i][j]='.';
			}
		}
	}
	bfs({start}, dist1, p1);
	bfs(monsters, dist2, p2);

	for(int i=0;i<n;i++){
		if(graph[i][0]=='.'){

			if(dist1[i][0] < dist2[i][0]){
				cout<<"YES\n";
				print_path(i, 0);
				return;
			}

		}

		if(graph[i][m-1]=='.'){
			if(dist1[i][m-1] < dist2[i][m-1]){
				cout<<"YES\n";
				print_path(i, m-1);
				return;
			}
		}
	}

	for(int i=0;i<m;i++){
		if(graph[0][i]=='.'){

			if(dist1[0][i] < dist2[0][i]){
				cout<<"YES\n";
				print_path(0, i);
				return;
			}

		}

		if(graph[n-1][i]=='.'){
			if(dist1[n-1][i] < dist2[n-1][i]){
				cout<<"YES\n";
				print_path(n-1, i);
				return;
			}
		}
	}

	cout<<"NO\n";

	//print_matrix(graph);
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);

    solve();

	return 0;
}


/*
Logic:

Step 1: Apply BFS for all monsters. Store in dist array, dist[i][j], shortest time among all monsters to reach, coordinate (i, j).

Step 2: Apply BFS for A. Store in d array, shortest time from A to coordinate (i, j). It is only possible to reach that coordinate if d[i][j] < dist[i][j]. Check if we have reached the border.

Step 3: Backtrack to generate the path. 
*/