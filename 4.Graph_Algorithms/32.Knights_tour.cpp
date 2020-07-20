#include <bits/stdc++.h>  
using namespace std;

int a[8][8];

void print(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			//cout<<setw(4)<<a[i][j]<<" ";
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	//cout<<"-----------------------------------\n";
}

bool isSafe(int x,int y){
	if(x>=0 && x<8 && y>=0 && y<8)
		return true;
	return false;
}

int movesX[]={2,1,-1,-2,-2,-1,1,2};
int movesY[]={-1,-2,-2,-1,1,2,2,1};

int valid_places(int x, int y){
	int moves=0;
	for(int d=0;d<8;d++){
		int xx = x + movesX[d];
		int yy = y + movesY[d];
		if(isSafe(xx,yy) && a[xx][yy]==0){
			moves++;
		}
	}
	return moves;
}

vector<pair<int,int>> heuristic(int x,int y){
	vector<pair<int,int>> v;
	for(int d=0;d<8;d++){
		int xx = x + movesX[d];
		int yy = y + movesY[d];
		if(isSafe(xx,yy) && a[xx][yy]==0){
			v.push_back({valid_places(xx,yy), d});
		}
	}
	sort(v.begin(), v.end());
	return v;
}


//Warnsdorff’s algorithm approach

//solution:
//https://www.geeksforgeeks.org/warnsdorffs-algorithm-knights-tour-problem/

//------------------------|
// 						  |
// 						  | //don't use reference here
// 						  V
void dfs(int x,int y,int count,int &flag){
	//print();

	if(flag!=0)
		return;

	if(count>64){
		flag=1;
		return;
	}

	vector<pair<int,int>> v = heuristic(x,y); 

	for(auto p : v){
		int d = p.second;

		int xx = x + movesX[d];
		int yy = y + movesY[d];

		a[xx][yy]=count;
		dfs(xx,yy,count+1,flag);
		if(flag==0)
			a[xx][yy]=0;
		else{
			return;
		}
	}
}

int main(){
	memset(a,0,sizeof(a));
	int x,y;
	cin>>x>>y;
	x--;
	y--;
	int count=1;
	int flag=0;
	a[y][x]=count;
	dfs(y,x,count+1,flag);
	//sort(*a,*a+64);
	print();
	return 0;
}