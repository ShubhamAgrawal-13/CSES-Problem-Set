#include<iostream>
using namespace std;

#define INF 1e9+7

void print(int array[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void solve(int a[], int n, int w)
{
	int c[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		int sum=a[i];
		for(int j=i+1;j<n;j++)
		{
			int t=w-sum;
			if(sum<=w)
			{
				c[i][j]=t*t;
				sum+=a[j]+1;
			}
			else
			{
				c[i][j]=INF;
			}
			
		}
	}
}

int main()
{
	// int n;
	// cin>>n;
	// int a[n];
	// for(int i=0;i<n;i++)
	// {
	// 	cin>>a[i];
	// }
	int n=4;
	int w=6;
	int a[]={3,2,2,5};
	solve(a,n,w);
	return 0;
}