#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
char board[MAX][MAX];
int n;
int count1=0;

void print()
{
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n";
}

void cprint()
{
	cout<<"\n";
	cout<<"Count : "<<count1<<"\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n";
}

bool check_safe(int row, int col)
{
	//reserved position
	if(board[row][col]=='*')
		return false;

	//row
	for(int i=0;i<n;i++)
	{
		if(board[row][i]=='Q')
			return false;
	}

	//col
	for(int i=0;i<n;i++)
	{
		if(board[i][col]=='Q')
			return false;
	}

	//diagonal right
	int r=row;
	int c=col;
	while(r>=0 && c>=0)
	{
		if(board[r][c]=='Q')
			return false;
		r--;
		c--;
	}
	r=row;
	c=col;
	while(r<n && c<n)
	{
		if(board[r][c]=='Q')
			return false;
		r++;
		c++;
	}

	//diagonal left
	r=row;
	c=col;
	while(r>=0 && c<n)
	{
		if(board[r][c]=='Q')
			return false;
		r--;
		c++;
	}
	r=row;
	c=col;
	while(r<n && c>=0)
	{
		if(board[r][c]=='Q')
			return false;
		r++;
		c--;
	}

	return true;
}

void solve(int col)
{
	if(col==n)
	{
		count1++;
		//cprint();
		return; 
	}
	for(int i=0;i<n;i++)
	{
		if(check_safe(i,col))
		{
			board[i][col]='Q';
			solve(col+1);
			board[i][col]='.';
		}
	}
}


int main()
{
	n=8;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>board[i][j];
		}
	}
	solve(0);
	cout<<count1<<"\n";
	return 0;
}