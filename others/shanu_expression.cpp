#include <bits/stdc++.h>  
using namespace std;

void backtrack(vector<int> &a, vector<int> &op, int &target, map<int,int> &m, int &sum,int &flag){

	if(flag==1){
		return;
	}

	if(m.size()>5){
		return;
	}

	if(m.size()==5 && sum == target){
		flag=1;
		return;
	}

	for(int i=0;i<5;i++){
		if(m.find(i)==m.end()){
			m[i]=1;
			for(int j=0;j<3;j++){
				if(j==0){
					sum+=a[i];
					backtrack(a,op,target,m,sum,flag);
					sum-=a[i];
				}

				if(j==1){
					sum-=a[i];
					backtrack(a,op,target,m,sum,flag);
					sum+=a[i];
				}

				if(j==2){
					sum*=a[i];
					backtrack(a,op,target,m,sum,flag);
					sum/=a[i];
				}

			}
			m.erase(i);
		}
	}
}

void solve(){

	int n=5,target;
	vector<int> a(5);
	vector<int> op(3,0);
	op[0]=0;
	op[1]=1;
	op[2]=2;

	for(int i=0;i<5;i++){
		cin>>a[i];
	}

	cin>>target;

	map<int,int> m;
	int sum=0;
	int flag=0;
	for(int i=0;i<n;i++){
		m[i]=1;
		sum+=a[i];
		backtrack(a,op,target,m,sum,flag);
		m.erase(i);
		sum-=a[i];
	}

	if(flag==1){
		cout<<"Possible\n";
	}
	else{
		cout<<"Impossible\n";
	}
}

int main(){

	ios_base::sync_with_stdio(false);  
    cin.tie(NULL);  
    cout.tie(0);
  

	int t;
	cin>>t;

	while(t--)
		solve();

	return 0;
}