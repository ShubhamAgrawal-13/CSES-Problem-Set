#include <bits/stdc++.h>  
using namespace std;

#define ll long long 

int main(){
	int n;
	cin>>n;

	vector<int> length;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;

		auto it = lower_bound(length.begin(), length.end(), x);
		if(it==length.end())
			length.push_back(x);
		else
		{
			*it = x;
		}
	}
	cout<<length.size()<<"\n";
	return 0;
}