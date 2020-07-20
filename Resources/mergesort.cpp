#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;


void merging(int a[],int l,int m,int h)
{
	int b[h+1];
	memset(b,0,sizeof(b));
	int i=l;
	int j=m+1;
	int k=l;

	while(i<=m && j<=h)
	{
		if(a[i]>a[j])
		{
			b[k++]=a[j++];
		}
		else
		{
			b[k++]=a[i++];
		}
	}

	while(i<=m)
	{
		b[k++]=a[i++];
	}

	while(j<=h)
	{
		b[k++]=a[j++];
	}

	for(int i=l;i<=h;i++)
	{
		a[i]=b[i];
	}
}

void mergesort(int a[],int l,int h)
{
	if(l<h)
	{
		int m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merging(a,l,m,h);
	}
}

int main()
{
	cout<<"Merge sort : \n";
	int n;
	cout<<"Enter n : ";
	cin>>n;
	int a[n];
	cout<<"Enter elements in array : \n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	//sort(as,as+SIZE);
	cout<<"Sorted Array : \n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}